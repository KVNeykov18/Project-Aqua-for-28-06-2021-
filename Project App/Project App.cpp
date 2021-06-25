#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include "LoginSystem.h"
using namespace std;
int main()
{
    User user("Bob", "The Destroyed", "destroyed@gmail.com", "assblaster", true);
    std::fstream file;
    file.open(".\\file.txt");
    bool yes = file.is_open();
    user.saveUser();
}