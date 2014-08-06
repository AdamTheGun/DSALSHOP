#include "Shopper.h"


Shopper::Shopper(void)
{
	totalAmount = 0.0f;
	sameTotal = true;
}


Shopper::~Shopper(void)
{
}

Shopper::Shopper(string inUsername,int inID)
{
	username = inUsername;
	userID = inID;
}

void Shopper::addToCart(Games &newGame)
{
	CartOfGames.push_back(newGame);
	sameTotal = false;
	cout << newGame.getTitle() << " has been added to your cart!";
}

void Shopper::removeFromCart(int chosenID)
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		if(GameItor->getID() == chosenID)
		{
			cout << GameItor->getTitle() << " has been removed from your cart";
			GameItor = CartOfGames.erase(GameItor);
			break;
		}
	}
	sameTotal = false;
}

void Shopper::printCart()
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		cout << "======================================================" << endl;
		GameItor->printProdInfo();
		cout << "======================================================" << endl;
	}
	cout << "Your Cart Total: " << this->getTotal();

}

void Shopper::calculateTotal()
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		totalAmount += GameItor->getCost();
	}
}

float Shopper::getTotal()
{
	if(!sameTotal)
	{
		calculateTotal();
	}
	return totalAmount;
}
