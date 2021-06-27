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
    User user("Zachary", "The Destroyed", "destroyed@gmail.com", "assblaster", false);
    Menus menu;
    menu.printMainMenu();
}