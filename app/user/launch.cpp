#include "launch.h"

// Định nghĩa các biến toàn cục
mutex foundPathsMutex;
unordered_map<string, vector<string>> searchCache;
const string CACHE_FILE = "cache/cache.txt";
unordered_set<string> skipDirs = {
#ifdef _WIN32
    "System32", "Windows", "$Recycle.Bin", "ProgramData",
#else
    "proc", "sys", "dev", "tmp", "var",
#endif
    ".git", "node_modules", "__pycache__"
};

// Hàm chuyển đổi chuỗi thành chữ thường
string ToLowerCase(const string& str) {
    string result = str;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}

// Hàm chuyển đổi wstring sang string trên Windows
#ifdef _WIN32
string WideToMultiByte(const wstring& wstr) {
    if (wstr.empty()) return "";
    int size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    string result(size - 1, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &result[0], size, nullptr, nullptr);
    return result;
}
#endif

// Hàm kiểm tra file có tồn tại hay không
bool FileExists(const string& filePath) {
#ifdef _WIN32
    wstring wFilePath(filePath.begin(), filePath.end());
    DWORD fileAttr = GetFileAttributesW(wFilePath.c_str());
    return (fileAttr != INVALID_FILE_ATTRIBUTES && !(fileAttr & FILE_ATTRIBUTE_DIRECTORY));
#else
    struct stat buffer;
    return (stat(filePath.c_str(), &buffer) == 0 && S_ISREG(buffer.st_mode));
#endif
}

// Hàm lấy tên file từ đường dẫn
string GetFileNameFromPath(const string& path) {
    size_t pos = path.find_last_of("/\\");
    return (pos == string::npos) ? path : path.substr(pos + 1);
}

// Hàm kiểm tra xem thư mục có nên bỏ qua hay không
bool ShouldSkipDir(const string& dirName) {
    return skipDirs.count(dirName) > 0;
}

// Hàm tải cache từ file
void LoadCacheFromFile() {
    ifstream cacheFile(CACHE_FILE);
    if (!cacheFile.is_open()) return;

    string line;
    while (getline(cacheFile, line)) {
        size_t pos = line.find(':');
        if (pos == string::npos) continue;

        string key = line.substr(0, pos);
        string paths = line.substr(pos + 1);

        vector<string> pathList;
        stringstream ss(paths);
        string path;
        while (getline(ss, path, '|')) {
            if (!path.empty()) pathList.push_back(path);
        }

        searchCache[key] = pathList;
    }
    cacheFile.close();
}

// Hàm lưu cache vào file
void SaveCacheToFile() {
    ofstream cacheFile(CACHE_FILE);
    if (!cacheFile.is_open()) {
        cout << "Failed to save cache to file!" << endl;
        return;
    }

    for (unordered_map<string, vector<string>>::const_iterator it = searchCache.begin(); it != searchCache.end(); ++it) {
        const string& key = it->first;
        const vector<string>& paths = it->second;
        if (paths.empty()) continue;

        cacheFile << key << ":";
        for (size_t i = 0; i < paths.size(); ++i) {
            cacheFile << paths[i];
            if (i < paths.size() - 1) cacheFile << "|";
        }
        cacheFile << "\n";
    }
    cacheFile.close();
}

// Hàm tìm kiếm file nhanh bằng công cụ hệ thống
vector<string> QuickSearch(const string& fileName) {
    vector<string> results;
    string lowerFileName = ToLowerCase(fileName);
    string command;
#ifdef _WIN32
    command = "where " + fileName + " 2>nul";
#else
    command = "which " + fileName + " 2>/dev/null";
#endif

#ifdef _WIN32
    FILE* pipe = _popen(command.c_str(), "r");
#else
    FILE* pipe = popen(command.c_str(), "r");
#endif
    if (!pipe) return results;

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        string path(buffer);
        path.erase(path.find_last_not_of("\r\n") + 1); // Xóa ký tự xuống dòng
        if (FileExists(path)) {
            results.push_back(path);
        }
    }

#ifdef _WIN32
    _pclose(pipe);
#else
    pclose(pipe);
#endif
    return results;
}

// Hàm tìm kiếm file trong một thư mục
void SearchFile(const string& directory, const string& fileName, vector<string>& foundPaths, int maxDepth, int currentDepth) {
    if (currentDepth > maxDepth) return;

    string lowerFileName = ToLowerCase(fileName);

#ifdef _WIN32
    wstring wDirectory(directory.begin(), directory.end());
    wstring searchPath = wDirectory + L"\\*";
    WIN32_FIND_DATAW findFileData;
    HANDLE hFind = FindFirstFileW(searchPath.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        return;
    }

    do {
        wstring fileOrDir = findFileData.cFileName;
        if (fileOrDir == L"." || fileOrDir == L"..") continue;

        wstring fullPath = wDirectory + L"\\" + fileOrDir;
        string narrowFullPath = WideToMultiByte(fullPath);
        string dirName = GetFileNameFromPath(narrowFullPath);

        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (!ShouldSkipDir(dirName)) {
                SearchFile(narrowFullPath, fileName, foundPaths, maxDepth, currentDepth + 1);
            }
        } else {
            string fileNameFromPath = GetFileNameFromPath(narrowFullPath);
            if (ToLowerCase(fileNameFromPath) == lowerFileName) {
                lock_guard<mutex> lock(foundPathsMutex);
                foundPaths.push_back(narrowFullPath);
            }
        }
    } while (FindNextFileW(hFind, &findFileData) != 0);

    FindClose(hFind);
#else
    DIR* dir = opendir(directory.c_str());
    if (!dir) return;

    struct dirent* entry;
    struct stat statbuf;

    while ((entry = readdir(dir)) != nullptr) {
        string fileOrDir = entry->d_name;
        if (fileOrDir == "." || fileOrDir == "..") continue;

        string fullPath = directory + "/" + fileOrDir;
        stat(fullPath.c_str(), &statbuf);

        if (S_ISDIR(statbuf.st_mode)) {
            if (!ShouldSkipDir(fileOrDir)) {
                SearchFile(fullPath, fileName, foundPaths, maxDepth, currentDepth + 1);
            }
        } else {
            string fileNameFromPath = GetFileNameFromPath(fullPath);
            if (ToLowerCase(fileNameFromPath) == lowerFileName) {
                lock_guard<mutex> lock(foundPathsMutex);
                foundPaths.push_back(fullPath);
            }
        }
    }
    closedir(dir);
#endif
}

// Hàm tạo và chạy shell script để khởi động phần mềm với tham số tùy chọn
bool CreateAndRunLaunchScript(const string& filePath, const string& arguments) {
    ofstream launchScript("bin/launch.sh");
    if (!launchScript.is_open()) {
        cout << "Failed to create launch.sh!" << endl;
        return false;
    }

    launchScript << "#!/bin/bash\n";

#ifdef _WIN32
    string winPath = filePath;
    for (char& c : winPath) {
        if (c == '\\') c = '/';
    }
    launchScript << "cmd.exe /C start \"\" \"" << winPath << "\" " << arguments << "\n";
#elif __APPLE__
    launchScript << "open \"" << filePath << "\" --args " << arguments << "\n";
#else
    launchScript << "xdg-open \"" << filePath << "\" " << arguments << " || chmod +x \"" << filePath << "\" && \"" << filePath << "\" " << arguments << "\n";
#endif

    launchScript.close();

#ifdef _WIN32
    int result = system("bash bin/launch.sh");
#else
    system("chmod +x launch.sh");
    int result = system("./bin/launch.sh");
#endif

    if (result == 0) {
        cout << "Successfully launched using launch.sh: " << filePath << " with arguments: " << arguments << endl;
        return true;
    } else {
        cout << "Failed to launch using launch.sh!" << endl;
        return false;
    }
}

// Hàm chính để chạy chương trình
void RunLauncher() {
    // Tải cache từ file khi khởi động
    LoadCacheFromFile();

    string softwareName;
    cout << "Enter the software name to search and launch (e.g., notepad.exe, gedit, finder): ";
    getline(cin, softwareName);

    string arguments;
    cout << "Enter arguments to pass to the software (optional, e.g., path to a file, or press Enter to skip): ";
    getline(cin, arguments);

    string lowerSoftwareName = ToLowerCase(softwareName);

    // Kiểm tra cache trước
    if (searchCache.count(lowerSoftwareName)) {
        cout << "Found in cache!" << endl;
        vector<string> foundPaths = searchCache[lowerSoftwareName];
        if (!foundPaths.empty()) {
            cout << "Found " << foundPaths.size() << " matches:" << endl;
            for (size_t i = 0; i < foundPaths.size(); ++i) {
                cout << i + 1 << ". " << foundPaths[i] << endl;
            }

            int choice;
            cout << "Enter the number of the file to launch (1-" << foundPaths.size() << "): ";
            cin >> choice;

            if (choice < 1 || choice > static_cast<int>(foundPaths.size())) {
                cout << "Invalid choice!" << endl;
                return;
            }

            CreateAndRunLaunchScript(foundPaths[choice - 1], arguments);
            return;
        }
    }

    // Tìm kiếm nhanh bằng công cụ hệ thống
    vector<string> quickResults = QuickSearch(softwareName);
    if (!quickResults.empty()) {
        searchCache[lowerSoftwareName] = quickResults;
        SaveCacheToFile(); // Lưu cache vào file sau khi tìm thấy
        cout << "Found " << quickResults.size() << " matches using quick search:" << endl;
        for (size_t i = 0; i < quickResults.size(); ++i) {
            cout << i + 1 << ". " << quickResults[i] << endl;
        }

        int choice;
        cout << "Enter the number of the file to launch (1-" << quickResults.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > static_cast<int>(quickResults.size())) {
            cout << "Invalid choice!" << endl;
            return;
        }

        CreateAndRunLaunchScript(quickResults[choice - 1], arguments);
        return;
    }

    // Danh sách các thư mục gốc để tìm kiếm nếu không tìm thấy bằng quick search
    vector<string> rootDirs;
#ifdef _WIN32
    rootDirs = { "C:\\Program Files", "C:\\Program Files (x86)", "C:\\Windows" };
#else
    rootDirs = { "/usr/bin", "/usr/local/bin", "/bin", "/Applications" };
#endif

    vector<string> foundPaths;
    vector<future<void>> searchFutures;

    // Song song hóa tìm kiếm với std::async
    for (const auto& dir : rootDirs) {
        cout << "Starting search in " << dir << "..." << endl;
        searchFutures.emplace_back(async(launch::async, SearchFile, dir, softwareName, ref(foundPaths), 5, 0));
    }

    // Chờ tất cả các tác vụ hoàn thành
    for (auto& future : searchFutures) {
        future.wait();
    }

    if (foundPaths.empty()) {
        cout << "Software not found!" << endl;
        return;
    }

    // Lưu kết quả vào cache và file
    searchCache[lowerSoftwareName] = foundPaths;
    SaveCacheToFile();

    // Hiển thị danh sách các đường dẫn tìm thấy
    cout << "Found " << foundPaths.size() << " matches:" << endl;
    for (size_t i = 0; i < foundPaths.size(); ++i) {
        cout << i + 1 << ". " << foundPaths[i] << endl;
    }

    // Cho phép người dùng chọn file để khởi động
    int choice;
    cout << "Enter the number of the file to launch (1-" << foundPaths.size() << "): ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(foundPaths.size())) {
        cout << "Invalid choice!" << endl;
        return;
    }

    // Tạo và chạy file launch.sh để khởi động phần mềm với tham số
    CreateAndRunLaunchScript(foundPaths[choice - 1], arguments);
}