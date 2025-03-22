// STL - Standard Template Library for C++
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <future>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <sstream>


#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

// // Mutex để đồng bộ hóa khi thêm vào danh sách kết quả
// std::mutex foundPathsMutex;

// // Cache lưu kết quả tìm kiếm
// std::unordered_map<std::string, std::vector<std::string>> searchCache;

// // Tên file để lưu cache
// const std::string CACHE_FILE = "cache/launch.txt";