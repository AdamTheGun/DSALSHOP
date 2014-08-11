#pragma once
#include "shop.h"
#include <stdio.h>

class Admin
{
public:
	Admin(void);
	virtual ~Admin(void);

	void AdminMenu();
	
	void AddGame();
	void RemoveGame();
	void EditDetail();
};

