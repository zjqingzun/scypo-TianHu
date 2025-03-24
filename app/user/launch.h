#ifndef LAUNCH_H
#define LAUNCH_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <future>
#include <mutex>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

using namespace std;

// Mutex để đồng bộ hóa khi thêm vào danh sách kết quả
extern mutex foundPathsMutex;

// Cache lưu kết quả tìm kiếm
extern unordered_map<string, vector<string>> searchCache;

// Tên file để lưu cache
extern const string CACHE_FILE;

// Danh sách các thư mục/thư mục con cần bỏ qua
extern unordered_set<string> skipDirs;

// Khai báo các hàm
string ToLowerCase(const string& str);
#ifdef _WIN32
string WideToMultiByte(const wstring& wstr);
#endif
bool FileExists(const string& filePath);
string GetFileNameFromPath(const string& path);
bool ShouldSkipDir(const string& dirName);
void LoadCacheFromFile();
void SaveCacheToFile();
vector<string> QuickSearch(const string& fileName);
void SearchFile(const string& directory, const string& fileName, vector<string>& foundPaths, int maxDepth = 5, int currentDepth = 0);
bool CreateAndRunLaunchScript(const string& filePath, const string& arguments = "");
void RunLauncher(); // Hàm chính để chạy chương trình

#endif // LAUNCH_H