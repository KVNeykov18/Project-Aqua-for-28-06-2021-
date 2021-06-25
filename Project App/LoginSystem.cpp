#include "LoginSystem.h"


User::User()
{
	this->username = "bobthebomb";
	this->displayName = "Bob";
	this->userEmail = "bobExplosion@gmail.com";
	this->password = "BobistheexploderSUS";
	this->temporaryUser = true;
	this->moderator = false;
	this->admin = false;
}

User::User(std::string name, std::string displayName, std::string email, std::string password, bool tempUser, bool moderator, bool admin)
{
	this->username = name;
	this->displayName = displayName;
	this->userEmail = email;
	this->password = password;
	this->temporaryUser = tempUser;
	this->moderator = moderator;
	this->admin = admin;
}

void User::setUsername(std::string name)
{
	this->username = name;
}

void User::setDisplayName(std::string dispName)
{
	this->displayName = dispName;
}

void User::setUserEmail(std::string email)
{
	this->userEmail = email;
}

void User::setPassword(std::string pass)
{
	this->password = pass;
}

void User::setAdminPerms(bool admin)
{
	this->admin = admin;
}

void User::setModeratorPerms(bool mod)
{
	this->moderator = mod;
}

void User::setTempUser(bool tempUser)
{
	this->temporaryUser = tempUser;
}

std::string User::getUsername()
{
	return username;
}

std::string User::getDisplayName()
{
	return displayName;
}

std::string User::getUserEmail()
{
	return userEmail;
}

std::string User::getPassword()
{
	return password;
}

bool User::isAdmin()
{
	return admin;
}

bool User::isModerator()
{
	return moderator;
}

bool User::isTempUser()
{
	return temporaryUser;
}

bool User::saveUser()
{
	if (isTempUser())
	{
		std::cout << "This is a temporary user, are you sure you want to change the user to a permanent one? Y/N\n:";
		switch (_getch())
		{
		case 'y':
		case 'Y':
			setTempUser(false); saveUser(); return true;
		case 'n':
		case 'N':
			std::cout << "\nUser not saved.\nReturning to main menu..."; Sleep(1000);
			return true;
		default:
			return false;
			break;
		}
	}
	else
	{
		std::ofstream file;
		file.open(".\\file.txt");

		if (file.is_open())
		{
			file << username << "\n";
			file << displayName << "\n";
			file << password << "\n";
			file << userEmail << "\n";
			file << isTempUser() << "\n";
			file << isAdmin() << "\n";
			file << isModerator() << "\n";
			file.close();
			std::cout << "\nUser successfully saved.\nReturning to main menu..."; Sleep(1000); return true;
		}
		std::cout << "\nAn error occured\nReturning to main menu..."; Sleep(1000);
		return false;
	}
}

bool User::loadUsers()
{
	return false;
}