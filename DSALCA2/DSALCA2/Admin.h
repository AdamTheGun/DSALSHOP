#pragma once
#include "shop.h"
#include <stdio.h>

class Admin :
	public Shop
{
public:
	Admin(void);
	virtual ~Admin(void);
	
	void AddGame();
	void RemoveGame();
	void EditDetail();
};

