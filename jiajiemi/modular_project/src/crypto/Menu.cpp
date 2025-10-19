#include "../include/crypto/Menu.h"
#include "../include/crypto/FileHandler.h"
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

Menu::Menu() : currentAlgorithm(Crypto::Algorithm::CAESAR){}

void Menu::clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::pressAnyKeyToContinue(){
    cout<<"\n按任意键继续";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

string Menu::getInput(const string&prompt){
    string input;
    cout<<prompt;
    getline(cin,input);
    return input;  
}

void Menu::showMainMenu(){
    clearScreen();
    cout << "========================================\n";
    cout << "          文本加密解密工具\n";
    cout << "========================================\n";
    cout << "当前算法: " << (currentAlgorithm == Crypto::Algorithm::CAESAR ? "凯撒密码" : "XOR加密") << "\n";
    cout << "1. 文本加密\n";
    cout << "2. 文本解密\n";
    cout << "3. 文件加密\n";
    cout << "4. 文件解密\n";
    cout << "5. 选择加密算法\n";
    cout << "0. 退出程序\n";
    cout << "========================================\n";
    cout << "请选择功能 (0-5): ";
}

void Menu::algorithmSelectionMenu() {
    clearScreen();
    cout << "选择加密算法:\n";
    cout << "1. 凯撒密码 (Caesar Cipher)\n";
    cout << "2. XOR加密 (XOR Cipher)\n";
    cout << "请选择算法 (1-2): ";
    
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

      switch (choice) {
        case 1:
            currentAlgorithm = Crypto::Algorithm::CAESAR;
            cout << "已选择凯撒密码算法\n";
            break;
        case 2:
            currentAlgorithm = Crypto::Algorithm::XOR;
            cout << "已选择XOR加密算法\n";
            break;
        default:
            cout << "无效选择，保持当前算法\n";
    }
        pressAnyKeyToContinue();
}

void Menu::textEncryptionMenu(){
    clearScreen();
    cout << "文本加密\n";
    cout << "========\n";
    string text = getInput("请输入要加密的文本: ");
    string key = getInput("请输入密钥: ");

    try{
        string encrypted = crypto.encryptText(text,key,currentAlgorithm);
        cout << "加密结果: " << encrypted << endl;
    }
    catch(const exception& e){
        cout << "加密失败: " << e.what() << endl;
    }

    pressAnyKeyToContinue();
}

void Menu::textDecryptionMenu() {
    clearScreen();
    cout << "文本解密\n";
    cout << "========\n";
    
    string text = getInput("请输入要解密的文本: ");
    string key = getInput("请输入密钥: ");
    
    try {
        string decrypted = crypto.decryptText(text, key, currentAlgorithm);
        cout << "解密结果: " << decrypted << endl;
    } catch (const exception& e) {
        cout << "解密失败: " << e.what() << endl;
    }
    
    pressAnyKeyToContinue();
}
void Menu::fileEncryptionMenu() {
    clearScreen();
    cout << "文件加密\n";
    cout << "========\n";
    
    string inputFile = getInput("请输入要加密的文件路径: ");
    string outputFile = getInput("请输入输出文件路径: ");
    string key = getInput("请输入密钥: ");
    
    try {
        FileHandler fileHandler;
        string content = fileHandler.readFile(inputFile);
        string encrypted = crypto.encryptText(content, key, currentAlgorithm);
        
        if (fileHandler.writeFile(outputFile, encrypted)) {
            cout << "文件加密成功！结果已保存到: " << outputFile << endl;
        } else {
            cout << "文件写入失败！" << endl;
        }
    } catch (const std::exception& e) {
        cout << "文件加密失败: " << e.what() << endl;
    }
    
    pressAnyKeyToContinue();
}

void Menu::fileDecryptionMenu() {
    clearScreen();
    cout << "文件解密\n";
    cout << "========\n";
    
    string inputFile = getInput("请输入要解密的文件路径: ");
    string outputFile = getInput("请输入输出文件路径: ");
    string key = getInput("请输入密钥: ");
    
    try {
        FileHandler fileHandler;
        string content = fileHandler.readFile(inputFile);
        string decrypted = crypto.decryptText(content, key, currentAlgorithm);
        
        if (fileHandler.writeFile(outputFile, decrypted)) {
            cout << "文件解密成功！结果已保存到: " << outputFile << endl;
        } else {
            cout << "文件写入失败！" << endl;
        }
    } catch (const exception& e) {
        cout << "文件解密失败: " << e.what() << endl;
    }
    
    pressAnyKeyToContinue();
}

void Menu::processInput() {
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    switch (choice) {
        case 0:
            cout << "感谢使用，再见！" << endl;
            break;
        case 1:
            textEncryptionMenu();
            break;
        case 2:
            textDecryptionMenu();
            break;
        case 3:
            fileEncryptionMenu();
            break;
        case 4:
            fileDecryptionMenu();
            break;
        case 5:
            algorithmSelectionMenu();
            break;
        default:
            cout << "无效选择，请重新输入！" << endl;
            pressAnyKeyToContinue();
    }
}

void Menu::run() {
    int choice = -1;
    
    while (choice != 0) {
        showMainMenu();
        processInput();
    }
}