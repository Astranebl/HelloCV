#include <sys/stat.h>
#include "../include/crypto/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

string FileHandler::readFile(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        throw runtime_error("不能打开文件"+filename);
    }

    stringstream buffer;
    buffer<<file.rdbuf();
    return buffer.str();
}

bool FileHandler::writeFile(const string& filename,const string& content){
    ofstream file(filename);
    if(!file.is_open()){
        return false;
    }

    file<<content;
    return true;
}

bool FileHandler::fileExists(const string& filename){
    struct stat buffer;
    return (stat(filename.c_str(),&buffer)==0);
}

size_t FileHandler::getFileSize(const string& filename){
    struct stat buffer;
    if(stat(filename.c_str(),&buffer)!=0){
        return 0;
    }
    return buffer.st_size;
}