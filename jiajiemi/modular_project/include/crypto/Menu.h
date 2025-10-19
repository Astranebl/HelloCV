#ifndef MENU_H
#define MENU_H

#include <string>
#include "Crypto.h"
using namespace std;

class Menu{
public:
    Menu();
    ~Menu() = default;

    void showMainMenu();//显示主菜单
    void processInput();//处理用户输入
    void run();//运行菜单循环

private:
    Crypto crypto;
    Crypto::Algorithm currentAlgorithm;

    void textEncryptionMenu();
    void textDecryptionMenu();
    void fileEncryptionMenu();
    void fileDecryptionMenu();
    void algorithmSelectionMenu();

    void clearScreen();
    void pressAnyKeyToContinue();
    string getInput(const string& prompt);
};
#endif