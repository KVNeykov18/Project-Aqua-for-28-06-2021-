#pragma once
#include <iostream>
#include <string>


class Menus
{
public:
	Menus();

	void printMainMenu();
	void printUserCreationMenu();
	void printUserEditingMenu();
private:
	std::string mainMenu;
	std::string userCreationMenu;
	std::string userEditingMenu;

};
