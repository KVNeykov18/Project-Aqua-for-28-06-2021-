#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include "LoginSystem.h"
#include "Menus.h"
using namespace std;

int main()
{
    User user("Zachary", "this guy", "zachary@gmail.com", "password", false,true,true);
    Menus menu;
    user.saveUser();
    menu.printMainMenu();
}