#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include "LoginSystem.h"
using namespace std;
int main()
{
    User user("Zachary", "The Destroyed", "destroyed@gmail.com", "assblaster", false);
    user.saveUser();
    system("CLS");
    User user2;
    user2.loadUser("Zachary");
    cout << user2.getDisplayName();
}