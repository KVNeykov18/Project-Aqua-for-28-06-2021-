#include "Menus.h"

std::vector<User> arr;

Menus::Menus()
{
	mainMenu = "  MAIN MENU\n=============\n1. Show monitoring options\n2. Show user management options\n0. Exit app";
	userManagementMenu = "  User Management\n===================\n1. Create a new user\n2. Edit an existing user\n3. Save an existing user\n4. Load a user\n0. Back to main menu";
}

void Menus::printMainMenu()
{
	system("CLS");
	std::cout << mainMenu;
	switch (_getch())
	{
	case'1':
		break;
	case '2':
		printUserManagementOptions();
		break;
	case '0':
		for (size_t i = 0; i < arr.size(); i++)
		{
			if (!arr[i].isTempUser())
			{
				arr[i].saveUser();
			}
		}
		break;
	default:
		system("CLS");
		std::cout << "Please enter a valid option"; Sleep(1000);  printMainMenu();
		break;
	}
}

void Menus::printUserManagementOptions()
{
	system("CLS");
	std::cout << userManagementMenu;
	std::string temp;
	bool tempB;
	User tempUser;
	switch (_getch())
	{
	case '1':
		system("CLS");
		std::cout << "Enter username: "; std::cin >> temp;
		tempUser.setUsername(temp);
		std::cout << "Enter display name: "; std::cin >> temp;
		tempUser.setDisplayName(temp);
		std::cout << "Enter password: "; std::cin >> temp;
		tempUser.setPassword(temp);
		std::cout << "Enter email: "; std::cin >> temp;
		tempUser.setUserEmail(temp);
		std::cout << "Is the user temporary? (1/0): "; std::cin >> tempB;
		tempUser.setTempUser(tempB);
		std::cout << "Is the user a moderator? (1/0): "; std::cin >> tempB;
		tempUser.setModeratorPerms(tempB);
		std::cout << "Is the user an admin? (1/0): "; std::cin >> tempB;
		tempUser.setAdminPerms(tempB);
		arr.push_back(tempUser);
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':

		break;
	case '0':
		break;

	default:
		system("CLS");
		std::cout << "Please enter a valid option"; Sleep(1000); printUserManagementOptions();
		break;
	}
}

void Menus::printWaterBodyManagementOptions()
{
}
