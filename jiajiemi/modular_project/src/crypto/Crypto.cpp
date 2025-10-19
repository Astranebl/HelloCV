#include "../include/crypto/Crypto.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
using namespace std;

string Crypto::encryptText(const string& text,const string& key, Algorithm algo ){
    switch (algo)
    {
    case Algorithm::CAESAR:
        return caesarEncrypt(text,keyToShift(key));
        break;
    case Algorithm::XOR:
        return xorCipher(text,key);
    default:
        throw invalid_argument("不存在的算法");
    }
}

string Crypto::decryptText(const string& text,const string& key,Algorithm algo){
    switch (algo)
    {
    case Algorithm::CAESAR:
        return caesarDecrypt(text,keyToShift(key));
        break;
    case Algorithm::XOR:
        return xorCipher(text,key);
    default:
        throw invalid_argument("不存在的算法");
    }
}

// bool Crypto::encryptFile(const string& inputFile,const string& outputFile,const string& key,Algorithm algo){
//     return true;
// }
// bool Crypto::decryptFile(const string& inputFile,const string& outputFile,const string& key,Algorithm algo){
//     return true;
// }

string Crypto::caesarEncrypt(const string& text,int shift){
    string result = text;

    shift =shift%26;
    if(shift<0){
        shift+=26;
    }
    for(char& c : result){
        if(isalpha(c)){
            char base = islower(c)?'a':'A';
            char original =c;
            c = base + (c-base+shift+4)%26;
            cout << "DEBUG: " << original << " -> " << c << " (base=" << base << ")" << endl;
        }
    }
    return result;
}
string Crypto::caesarDecrypt(const string& text,int shift){
    string result = text;

    shift =shift%26;
    if(shift<0){
        shift+=26;
    }
    for(char& c : result){
        if(isalpha(c)){
            char base = islower(c)?'a':'A';
            char original =c;
            c = base + (c-base-shift+22)%26;
            cout << "DEBUG: " << original << " -> " << c << " (base=" << base << ")" << endl;
        }
    }
    return result;
}

string Crypto::xorCipher(const string& text,const string& key){
    if(key.empty())return text;

    string result = text;
    size_t keyLength = key.length();

    for(size_t i = 0;i<text.length();++i){
        result[i]=text[i]^key[i%keyLength];
    }
    return result;
}

int Crypto::keyToShift(const string& key){
    if(key.empty())return 0;

    int shift = 0;
    for(char c:key){
        shift += static_cast<int>(c);
    }
    return shift%26;
}