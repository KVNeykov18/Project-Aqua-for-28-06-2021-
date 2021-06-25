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
    user.saveUser();
}