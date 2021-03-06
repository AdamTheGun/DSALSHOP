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
	
	static bool sortByCostLowToHigh(Games*,Games*);
	static bool sortByTitle(Games*,Games*);
	static bool sortByCostHigh2Low(Games*,Games*);
	static bool sortByRatingAsc(Games*,Games*);
	static bool sortByRatingDesc(Games*,Games*);
private:
	list<Games*> CartOfGames;
	float totalAmount;	
	bool sameTotal;
	
};

