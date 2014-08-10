#pragma once
#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	User(void);
	User(int);
	~User(void);
	void setUsername(string);
	int getUserID();
	string getUsername();
protected:
	string username;
	int userID;

};

