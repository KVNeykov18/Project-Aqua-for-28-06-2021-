#include "Menus.h"

std::vector<User> arr;
User currentUser("", "", "", "", 1);

void Menus::printMainMenu()
{
	system("CLS");
	if (currentUser.getUsername() == "")
	{
		std::cout << "Not Logged In"<< "\n\n";
		std::cout << "MAIN MENU\n=============\n3. Login\n0. Exit app";
	}
	else
	{
		std::cout << "Current User: " + currentUser.getDisplayName()<<"\n\n";
		std::cout << "MAIN MENU\n=============\n1. Show monitoring options\n2. Show user management options\n3. Login\n0. Exit app";
	}
	std::string temp;
	User tempUser;
	switch (_getch())
	{
	case '1':
		system("CLS");
		std::cout << "Work in progress.\nReturning to previous menu..."; Sleep(1000);
		system("CLS"); printUserManagementOptions();
		break;
	case '2':
		printUserManagementOptions();
		break;
	case '3':
		system("CLS");
		std::cout << "Enter username: "; std::cin >> temp;
		while (!(tempUser.loadUser(temp)))
		{
			std::cout << "User not found";
			Sleep(1000);
			system("CLS");
			std::cout << "Enter username: "; std::cin >> temp;
		}
		std::cout << "Enter password: ";
		std::cin >> temp;
		while (!(tempUser.getPassword() == temp))
		{
			system("CLS");
			std::cout << "Incorrect password";
			Sleep(1000);
			system("CLS");
			std::cout << "Enter password: "; std::cin >> temp;
		}
		currentUser = tempUser;
		system("CLS"); printMainMenu();
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
	if (currentUser.isAdmin())
	{
	std::cout << "User Management\n===================\n1. Create a new user\n2. Edit an existing user\n3. Save an existing user\n4. Load a user\n0. Back to main menu";
	}
	else if (currentUser.isModerator())
	{
		std::cout << "User Management\n===================\n2. Edit an existing user\n3. Save an existing user\n0. Back to main menu";
	}
	else
	{
		std::cout << "User Management\n===================\n0. Back to main menu";
	}
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
		printUserManagementOptions();
		break;
	case '2':
		system("CLS");
		std::cout << "Enter username: "; std::cin >> temp;
		if (tempUser.loadUser(temp))
		{
			tempB = true;
		}
		else
		{
			for (size_t i = 0; i < arr.size(); i++)
			{
				if (arr[i].getUsername() == temp)
				{
					tempUser = arr[i];
					tempB = true; break;
				}
				tempB = false;
			}
		}
		if (tempB)
		{
			system("CLS");
			std::cout << "What do you wish to edit?\n1. Username\n2. Display name\n3. Password\n4. Email\n5. Permissions\n0. Go back";
			switch (_getch())
			{
			case '1':
				system("CLS");
				std::cout << "Enter new username: "; std::cin >> temp;
				tempUser.setUsername(temp);
				printUserManagementOptions();
				break;
			case '2':
				system("CLS");
				std::cout << "Enter new display name: "; std::cin >> temp;
				tempUser.setUsername(temp);
				printUserManagementOptions();
				break;
			case '3':
				system("CLS");
				std::cout << "Enter new password: "; std::cin >> temp;
				tempUser.setUsername(temp);
				printUserManagementOptions();
				break;
			case '4':
				system("CLS");
				std::cout << "Enter new email: "; std::cin >> temp;
				tempUser.setUsername(temp);
				printUserManagementOptions();
				break;
			case '5':
				system("CLS");
				std::cout << "1. Temporary User\n2. Moderator permissions\n3. Admin permissions";
				switch (_getch())
				{
				case '1':
					std::cout << "Enter new temporary perms: ";
					std::cin >> tempB;
					tempUser.setTempUser(tempB);
					break;
				case '2':
					std::cout << "Enter new moderator perms: ";
					std::cin >> tempB;
					tempUser.setModeratorPerms(tempB);
					break;
				case '3':
					std::cout << "Enter new admin perms: ";
					std::cin >> tempB;
					tempUser.setAdminPerms(tempB);
					break;
				default:
					break;
				}
				printUserManagementOptions();
				break;
			case '0':
				system("CLS");
				printUserManagementOptions();
				break;
			default:
				system("CLS");
				std::cout << "Please enter a valid option"; Sleep(1000); printUserManagementOptions();
				break;
			}
		}
		break;
	case '3':
		system("CLS");
		for (size_t i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i].getUsername()<<std::endl;
		}
		std::cout << "Enter username of user you wish to save: ";
		std::cin >> temp;
		do
		{
			for (size_t i = 0; i < arr.size(); i++)
			{
				if (arr[i].getUsername() == temp)
				{
					arr[i].saveUser();
					tempB = true;
				}
			}

		} while (!tempB);
		
		printUserManagementOptions();
		break;
	case '4':
		system("CLS");
		std::cout << "Work in progress.\n0Returning to previous menu..."; Sleep(1000);
		system("CLS"); printUserManagementOptions();
		break;
	case '0':
		printMainMenu();
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
