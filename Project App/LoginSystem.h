#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

class User
{
public:
	//Constructors

	//Creates a user with default values
	User();
	//Creates a user with custom values
	User(std::string name, std::string displayName, std::string email, std::string password, bool tempUser, bool moderator = false, bool admin = false);




	//Setters


	void setUsername(std::string name);
	void setDisplayName(std::string dispName);
	void setUserEmail(std::string email);
	void setPassword(std::string pass);
	void setAdminPerms(bool admin);
	void setModeratorPerms(bool mod);
	void setTempUser(bool tempUser);


	//Getters

	//Returns the username of the user
	std::string getUsername();
	//Returns the display name of the user
	std::string getDisplayName();
	//Returns the email of the user
	std::string getUserEmail();
	//Returns the password of the user
	std::string getPassword();
	//Check if user is admin
	bool isAdmin();
	//Check if user is moderator
	bool isModerator();
	//Check if user is temporary
	bool isTempUser();

	//Save user to file
	bool saveUser();
	//Load user from file
	bool loadUser(std::string username);
private:
	std::string username;
	std::string displayName;
	std::string userEmail;
	std::string password;
	bool admin;
	bool moderator;
	bool temporaryUser;
};