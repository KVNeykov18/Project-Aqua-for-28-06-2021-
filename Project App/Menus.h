#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include "LoginSystem.h"

class Menus
{
public:
	Menus();

	void printMainMenu();
	void printUserManagementOptions();
	void printWaterBodyManagementOptions();
private:
	std::string mainMenu;
	std::string userManagementMenu;
	std::string waterBodyManagementMenu;

};
