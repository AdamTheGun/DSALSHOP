#pragma once
#include "user.h"
#include "Games.h"
#include <algorithm>
#include <list>
#include <windows.h>

class Shopper :
	public User
{
public:
	Shopper(void);
	~Shopper(void);
	Shopper(string,int);

	
	void addToCart(Games*);
	void removeFromCart(int);
	void emptyCart();
	void printCart();
	void calculateTotal();
	float getTotal();
	void shopperMainMenu(list<Games*> &);
	void viewGames(list<Games*> &);
	void searchGames(list<Games*> &);
	void sortGames(list<Games*> &);
	void cartActions(list<Games*> &);
	void addItemToCartPrint(list<Games*> &);
	void checkOut(list<Games*> &);
	void exitStore(list<Games*> &);
	bool sortByTitle(Games* const &,Games* const &);
	bool sortByCostLow2High(float,float);
	bool sortByCostHigh2Low(float,float);
	bool sortByRatingAsc(float,float);
	bool sortByRatingDesc(float,float);
private:
	list<Games*> CartOfGames;
	float totalAmount;	
	bool sameTotal;
	
};

