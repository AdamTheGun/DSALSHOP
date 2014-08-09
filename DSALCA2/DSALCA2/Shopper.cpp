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
	cout << endl<< newGame.getTitle() << " has been added to your cart!" << endl << endl;
	calculateTotal();
}

void Shopper::removeFromCart(int chosenID)
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();
	bool isDelete = false;

	for(;GameItor!=GameEndItor;GameItor++)
	{
		if(GameItor->getID() == chosenID)
		{
			cout << GameItor->getTitle() << " has been removed from your cart"<< endl;
			GameItor = CartOfGames.erase(GameItor);
			isDelete = true;
			break;
		}
	}
	if(isDelete == false)
	{
		cout << "Game not Found" << endl;
	}
	sameTotal = false;
}

void Shopper::emptyCart()
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();
	while(CartOfGames.empty()==false){
		for(;GameItor!=GameEndItor;GameItor++)
		{
			GameItor = CartOfGames.erase(GameItor);
		}
		GameEndItor = CartOfGames.erase(GameEndItor);
	}
	cout << "Cart is now empty" << endl;
}

void Shopper::printCart()
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();

	calculateTotal();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		cout << "======================================================" << endl << endl; 
		GameItor->printProdInfo();
		cout << "======================================================" << endl;
	}
	cout << "Your Cart Total: $" << this->getTotal() << endl << endl;
	
}

void Shopper::cartActions(list<Games> *inGames)
{
	int input;
	bool check = false;

	while(!check){
		cout << "1. Add Item to cart" << endl;
		cout << "2. Remove Item from cart" << endl;
		cout << "3. Check-Out" << endl;
		cout << "4. Return to main menu" << endl; 
		cout << "Input :" << endl;
		cin >> input;
		cout << endl;
		if(input)
		{
			switch(input)
			{
			case 1:viewGames(inGames);
				break;
			case 2:printCart();
				check = false;
				while(!check){
					cin.clear();
					cin.ignore( 1000, '\n' );
					cout << "Type '-999' to cancel" << endl;
					cout << "Enter the ID of the game to remove :" << endl;
					cin >> input;
					cout << endl;
					if(input)
					{
						if(input == -999)
						{
							shopperMainMenu(inGames);
							check = true;
						}
						else
						{
							removeFromCart(input);
							printCart();
							shopperMainMenu(inGames);
							check = true;
						}
					}
					else
					{
						cout << "Invalid input" << endl;	
					}
				}
				break;
			case 3:checkOut(inGames);
				check = true;
				break;
			case 4:shopperMainMenu(inGames);
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
			}
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
		cin.clear();
		cin.ignore( 1000, '\n' );
	}

}

void Shopper::checkOut(list<Games> *inGames)
{
	bool check = false;
	string input;
	cout << endl << "==================================Check-Out====================================" << endl << endl;
	printCart();

	while(!check){
		cout << "Would you like to check out your items?(Y/N)" << endl << "Input: ";
		cin >> input;
		cout << endl;
		if(input == "Y" || input == "y")
		{
			if(CartOfGames.empty()==false){
				emptyCart();
				cout << endl << "Thank you for your purchase.\nThe specified amount has been deducted from your account." << endl;
				cout << "You will receive your physical items  within one week from the date of purchase." << endl;
				printCart();
				check = true;
			}
			else
			{
				cout << "Cart is already empty!" << endl;
				check = true;
			}
		}
		else if(input == "N" || input == "n")
		{
			check = true;
		}
	}
	shopperMainMenu(inGames);
}

void Shopper::calculateTotal()
{
	list<Games>::iterator GameItor = CartOfGames.begin();
	list<Games>::iterator GameEndItor = CartOfGames.end();
	totalAmount = 0.0f;
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

void Shopper::shopperMainMenu(list<Games> *inGames)
{
	cout << endl << "Welcome " << username << endl << endl;
	int input;
	bool check = false;
	while(!check){
		cout << "1. View Games" << endl;
		cout << "2. Search Games" << endl;
		cout << "3. View Cart" << endl;
		cout << "4. Exit Store" << endl << endl;
		cin >> input;
		cout << endl;

		if(input >= 1 && input <= 4)
		{
			check = true;
		}
		else
		{
			cout << "Invalid input. Please try again" << endl << endl;
			cin.clear();
			cin.ignore( 1000, '\n' );
		}
	}
	switch(input)
			{
				case 1:viewGames(inGames);
					break;
				case 2:searchGames(inGames);
					break;
				case 3:printCart();
					cartActions(inGames);
					break;
				case 4:exitStore(inGames);
					break;
			}
}

void Shopper::addItemToCartPrint(list<Games> *inGames)
{
	bool check = false;
	int input;
	
	list<Games>::iterator GameEndItor = inGames->end();

	while(!check){
		list<Games>::iterator GameItor = inGames->begin();//Refreshes iterator
		cout << endl << "Add Game To Cart\nType '-999' to go back\nPlease enter the game ID:" << endl;

		//Clear input stream
		

		cin >> input;
		if(input)
		{
			if(input == -999)
			{
				viewGames(inGames);
			}
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if(GameItor->getID()==input)
				{
					addToCart((*GameItor));
					cout << endl << username << "'s Cart" << endl;
					printCart();
					shopperMainMenu(inGames);
					check = true;
				}
			}
			if(!check)
			{
				cout << "Product ID Invalid. Please Try Again." << endl;
				
			}
		}
		
		else
		{
			cout << "Invalid Input";
		}
		cin.clear();
		cin.ignore( 1000, '\n' );
	}
}


void Shopper::viewGames(list<Games> *inGames)
{
	int input;
	bool check = false;
	list<Games>::iterator GameItor = inGames->begin();
	

	cout << endl << "======================================================" << endl;
	for(;GameItor != inGames->end();GameItor++)
	{
		GameItor->printProdInfo();
	}
	cout << "======================================================" << endl << endl;
	while(!check){
		cout << "1. Add Game to cart" << endl;
		cout << "2. Search" << endl;
		cout << "3. Return to main menu" << endl;
		cin >> input;
		cout << endl;
		if(input >=1 && input <= 3)
		{
			check = true;
		}
		else
		{
			cout << "Invalid input" << endl;
			input = NULL;
			check = false;
			cin.clear();
			cin.ignore( 1000, '\n' );
		}
	}
	check = false;
	switch(input)
	{
		case 1:
			addItemToCartPrint(inGames);
			break;
		case 2:searchGames(inGames);
			break;
		case 3:shopperMainMenu(inGames);
			break;
		
	}
}



void Shopper::searchGames(list<Games> *inGames)
{
	int input;
	string searchInput;
	bool check = false;
	while(!check){
		cout << "Filter Search" << endl;
		cout << "1. Search by Publisher" << endl;
		cout << "2. Search by Developer" << endl;
		cout << "3. Search by Year" << endl;
		cout << "Input: " << endl;
		cin >> input;
		cout << endl;
				
		if(input >=1 && input <= 3)
		{
			check = true;	
		}	
		else
		{
			cout << "Invalid input" << endl;
			input = NULL;
			check = false;
			cin.clear();
			cin.ignore( 1000, '\n' );
		}
	}
	list<Games>::iterator GameItor = inGames->begin();
	list<Games>::iterator GameEndItor = inGames->end();

	cin.clear();
	cin.ignore( 1000, '\n' );

	switch(input){
		case 1:
			cout << "Publisher Search: ";
			getline(cin,searchInput);
			cout << endl << "Found Games" << endl;
			for(;GameItor!=GameEndItor;GameItor++)
			{
				
				if(GameItor->getPublisher()==searchInput)
				{
					cout << "======================================================" << endl;
					GameItor->printProdInfo();
					cout << "======================================================" << endl;
				}
			}
			break;
		case 2:
			cout << "Developer Search: ";
			getline(cin,searchInput);
			cout << endl << "Found Games" << endl;
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if(GameItor->getDeveloper()==searchInput)
				{
					cout << "======================================================" << endl;
					GameItor->printProdInfo();
					cout << "======================================================" << endl;
				}
			}
			break;
		case 3:
			cout << "Year Search: ";
			getline(cin,searchInput);
			cout << endl << "Found Games" << endl;
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if(GameItor->getYear()==searchInput)
				{
					cout << "======================================================" << endl;
					GameItor->printProdInfo();
					cout << "======================================================" << endl;
				}
			}
			break;
	}
	addItemToCartPrint(inGames);
}

void Shopper::exitStore(list<Games> *inGames)
{
	bool check = false;
	string input;

	while(!check)
	{
		cout << endl << "Are you sure you want to exit the store? (Y/N)" << endl << "Input: ";
		cin >>input;

		if(input == "Y" || input == "y")
		{
			cout << endl << "Thank you for using AK-DUO Online Game Store.\nHope to see you again\n\nLogging you out......";
			Sleep(2000);
			exit(0);
		}
		else if(input == "N" || input == "n")
		{
			check = true;
		}
		else
		{
			cout << "Invalid Input." << endl;
			cin.clear();
			cin.ignore( 1000, '\n' );
		}
	}
	shopperMainMenu(inGames);
}