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
	CartOfGames.push_back(&newGame);
	sameTotal = false;
	cout << newGame.getTitle() << " has been added to your cart!";
}

void Shopper::removeFromCart(int chosenID)
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		if((*GameItor)->getID() == chosenID)
		{
			cout << (*GameItor)->getTitle() << " has been removed from your cart";
			GameItor = CartOfGames.erase(GameItor);
			break;
		}
	}
	sameTotal = false;
}

void Shopper::printCart()
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		cout << "======================================================" << endl;
		(*GameItor)->printProdInfo();
		cout << "======================================================" << endl;
	}
	cout << "Your Cart Total: " << this->getTotal();

}

void Shopper::calculateTotal()
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		totalAmount += (*GameItor)->getCost();
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

int Shopper::shopperMainMenu()
{
	cout << "Welcome " << username << endl << endl;
	int input;
	bool check = false;
	while(!check){
		cout << "1. View Games" << endl;
		cout << "2. Search Games" << endl;
		cout << "3. View Cart" << endl;
		cout << "4. Exit Store" << endl << endl;
		cin >> input;

		if(input >= 1 && input <= 4)
		{
			check = true;

		}
		else
		{
			cout << "Invalid input. Please try again" << endl << endl;
		}
	}
	return input;
}


void Shopper::viewGames(list<Games*> &inGames)
{
	list<Games*>::iterator GameItor = inGames.begin();
	list<Games*>::iterator GameEndItor = inGames.end();

	cout << "======================================================" << endl;
	for(;GameItor != GameEndItor;GameItor++)
	{
		(*GameItor)->getTitle();
	}
	cout << "======================================================" << endl;

}

void Shopper::searchGames(list<Games*> &inGames)
{
	int input;
	string searchInput;
	bool check = false;
	while(!check){
		cout << "Filter Search" << endl;
		cout << "1. Search by Publisher" << endl;
		cout << "2. Search by Developer" << endl;
		cout << "3. Search by Year" << endl;
		cout << "Input: ";
		try{
			cin >> input;
		}catch(int e)
		{
			cout << "Invalid Input type" << endl; 
		}
		if(input >=1 && input <= 3)
		{
			check = true;	
		}	
		else
		{
			cout << "Invalid input" << endl;
		}
	}
		list<Games*>::iterator GameItor = inGames.begin();
		list<Games*>::iterator GameEndItor = inGames.end();

	switch(input){
		case 1:
			cout << "Publisher Search: ";
			cin >> searchInput;
			cout << endl;
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if((*GameItor)->getPublisher()==searchInput)
				{
					cout << "======================================================" << endl;
					(*GameItor)->printProdInfo();
					cout << "======================================================" << endl;
				}
			}
			break;
		case 2:
			cout << "Developer Search: ";
			cin >> searchInput;
			cout << endl;
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if((*GameItor)->getDeveloper()==searchInput)
				{
					cout << "======================================================" << endl;
					(*GameItor)->printProdInfo();
					cout << "======================================================" << endl;
				}
			}
			break;
		case 3:
			cout << "Year Search: ";
			cin >> searchInput;
			cout << endl;
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if((*GameItor)->getYear()==searchInput)
				{
					cout << "======================================================" << endl;
					(*GameItor)->printProdInfo();
					cout << "======================================================" << endl;
				}
			}
			break;
	}
}