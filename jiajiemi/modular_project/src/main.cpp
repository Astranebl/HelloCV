#include <iostream>
#include "../include/crypto/Menu.h"
using namespace std;

int main(){
    try{
        Menu menu;
        menu.run();
    }
    catch(const exception& e){
        cerr<<"程序错误"<<e.what()<<endl;
        return 1;
    }
    return 0;
}