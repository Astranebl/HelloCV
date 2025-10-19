#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <vector>
using namespace std;

class Crypto{
public:
    enum class Algorithm {//加密算法类型
        CAESAR,
        XOR
    };

    Crypto() = default;
    ~Crypto() = default;

    string encryptText(const string& text,const string& key, Algorithm algo = Algorithm::CAESAR);//文本加密
    string decryptText(const string& text,const string& key, Algorithm algo = Algorithm::CAESAR);//文本解密
    bool encryptFile(const string& inputFile,const string& outputFile,const string& key, Algorithm algo = Algorithm::CAESAR);//文件加密
    bool decryptFile(const string& inputFile,const string& outputFile,const string& key, Algorithm algo = Algorithm::CAESAR);//文件解密

private:
    string caesarEncrypt(const string& text,int shift);//凯撒加密
    string caesarDecrypt(const string& text,int shift);//凯撒解密
    string xorCipher(const string& text,const string& key);//XOR加解密
    int keyToShift(const string& key);//从字符串密钥生成整数移位
};
#endif