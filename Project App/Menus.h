#pragma once
#include <iostream>
#include <string>


class Menus
{
public:
	Menus();

	void printMainMenu();
	void printUserManagementOptions();
	void printWaterBodyManagementOptions();
private:
	std::string mainMenu;
	std::string userCreationMenu;
	std::string userEditingMenu;

};
