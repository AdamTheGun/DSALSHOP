#include "User.h"

User::User(void)
{
	username = "";
	userID = -1;
}

User::User(int inID)
{
	username = "";
	userID = inID;
}


User::~User(void)
{
}


void User::setUsername(string inUsername)
{
	username = inUsername;
}

int User::getUserID()
{
	return userID;
}

string User::getUsername()
{
	return username;
}
