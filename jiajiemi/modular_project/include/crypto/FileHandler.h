#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
using namespace std;

class FileHandler{
public:
    FileHandler() = default;
    ~FileHandler() = default;

    string readFile(const string& filename);//读取文件内容
    bool writeFile(const string& filename,const string& content);//写入文件内容
    bool fileExists(const string& filename);
    size_t getFileSize(const string& filename);

private:
    string currentDirectory;
};
#endif