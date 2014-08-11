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

//Adds Game to CartOfGames
//Takes in a Game pointer
void Shopper::addToCart(Games* newGame)
{
	CartOfGames.push_back(newGame);// Adds game to Cart
	sameTotal = false;//Resets the calculateTotal check
	cout << endl<< newGame->getTitle() << " has been added to your cart!" << endl << endl;
	calculateTotal();//Recalculate total
}

//Removes game from cart
//Uses GameId to search for game to delete from cart
void Shopper::removeFromCart(int chosenID)
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();
	bool isDelete = false;//to check if there was any game deleted

	for(;GameItor!=GameEndItor;GameItor++)
	{
		if((*GameItor)->getID() == chosenID)//Checks if input game was found in cart
		{
			cout << (*GameItor)->getTitle() << " has been removed from your cart"<< endl;
			GameItor = CartOfGames.erase(GameItor);
			isDelete = true;
			sameTotal = false;
			break;
		}
	}
	if(isDelete == false)//If there was no game deleted
	{
		cout << "Game not Found" << endl;
	}
	
}

//Empties cart totally
//To show that the user has purchased the games
void Shopper::emptyCart()
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();
	while(CartOfGames.empty()==false){//If the cart is not empty, keep erasing the game pointers from cart
		for(;GameItor!=GameEndItor;GameItor++)
		{
			GameItor = CartOfGames.erase(GameItor);
		}
		GameEndItor = CartOfGames.erase(GameEndItor);
	}
	cout << "Cart is now empty" << endl;
}


//Prints all games in the cart
//Shows the user's total
void Shopper::printCart()
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();

	calculateTotal();

	for(;GameItor!=GameEndItor;GameItor++)
	{
		cout << "======================================================" << endl << endl; 
		(*GameItor)->printProdInfo();
		cout << "======================================================" << endl;
	}
	cout << "Your Cart Total: $" << this->getTotal() << endl << endl;
	
}

//Prints out options for the user to maintain their cart
//Executes other functions from the given input from user
//Takes in the AllGames list to be used to run the mainmenu again or to view games
void Shopper::cartActions(list<Games*> &inGames)
{
	int input;
	bool check = false;//error checking

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
					cin.clear();//Clears the CIN cache
					cin.ignore( 1000, '\n' );
					cout << "Type '-999' to cancel" << endl;
					cout << "Enter the ID of the game to remove :" << endl;
					cin >> input;
					cout << endl;
					if(input)
					{
						if(input == -999)//Return to main menu
						{
							shopperMainMenu(inGames);
							check = true;
						}
						else//If input is valid, attempt to remove game from cart
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
			case 3:checkOut(inGames);//Checkouts games
				check = true;
				break;
			case 4:shopperMainMenu(inGames);//Return to main menu
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
		cin.clear();//Clears the CIN cache
		cin.ignore( 1000, '\n' );
	}

}

//Checkouts all games in the cart
//This is only for visual display only and does not actually send you games
//Empties Cart
void Shopper::checkOut(list<Games*> &inGames)
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
	cin.clear();//Clears the CIN cache
	cin.ignore( 1000, '\n' );
	shopperMainMenu(inGames);//Returns back to main menu
}

//Recalculates the total cost of games in cart
void Shopper::calculateTotal()
{
	list<Games*>::iterator GameItor = CartOfGames.begin();
	list<Games*>::iterator GameEndItor = CartOfGames.end();
	totalAmount = 0.0f;
	for(;GameItor!=GameEndItor;GameItor++)
	{
		totalAmount += (*GameItor)->getCost();
	}
}

//Accessor method to get total
//Also recalculates total before returning value
float Shopper::getTotal()
{
	if(!sameTotal)
	{
		calculateTotal();
	}
	return totalAmount;
}


//Main menu options
//User can view games
//search for games
//View their cart
//And exit the game
//This menu will lead the user to other more useful functions
void Shopper::shopperMainMenu(list<Games*> &inGames)
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
			cin.clear();//Clears the CIN cache
			cin.ignore( 1000, '\n' );
		}
	}
	switch(input)
			{
				case 1:viewGames(inGames);
					break;
				case 2:searchGames(inGames);
					break;
				case 3:printCart();//Prints out the games in the cart
					cartActions(inGames);// Shows the user the options available with the cart
					break;
				case 4:exitStore(inGames);
					break;
			}
}

//Function to add game to cart using ID
//Used in more than one function 
//So it is in a seperate function for code cleanliness
void Shopper::addItemToCartPrint(list<Games*> &inGames)
{
	bool check = false;
	int input;
	
	list<Games*>::iterator GameEndItor = inGames.end();

	while(!check){
		list<Games*>::iterator GameItor = inGames.begin();//Refreshes iterator
		cout << endl << "Add Game To Cart\nType '-999' to go back\nPlease enter the game ID:" << endl;


		cin >> input;
		if(input)
		{
			if(input == -999)
			{
				viewGames(inGames);//Return to view games available
			}
			for(;GameItor!=GameEndItor;GameItor++)
			{
				if((*GameItor)->getID()==input)//If ID matches, Adds game to the cart
				{
					addToCart(*GameItor);
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
		cin.clear();//Clears the CIN cache
		cin.ignore( 1000, '\n' );
	}
}

//Prints out all the game information on all games
//Takes input from user to allow user to add game,search,sort the games and return to main menu
void Shopper::viewGames(list<Games*> &inGames)
{
	int input;
	bool check = false;
	list<Games*>::iterator GameItor = inGames.begin();
	

	cout << endl << "======================================================" << endl;
	for(;GameItor != inGames.end();GameItor++)
	{
		(*GameItor)->printProdInfo();
	}
	cout << "======================================================" << endl << endl;
	while(!check){
		cout << "1. Add Game to cart" << endl;
		cout << "2. Search" << endl;
		cout << "3. Sort Games" << endl;
		cout << "4. Return to main menu" << endl;
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
		case 3://sortGames(inGames);
			break;
		case 4:shopperMainMenu(inGames);
			break;
		
	}
}

//Function for user to look for games by their publisher, developer or year or publish
//Shows only games that matches the search input
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
	list<Games*>::iterator GameItor = inGames.begin();
	list<Games*>::iterator GameEndItor = inGames.end();

	cin.clear();
	cin.ignore( 1000, '\n' );

	switch(input){
		case 1:
			cout << "Publisher Search: ";
			getline(cin,searchInput);
			cout << endl << "Found Games" << endl;
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
			getline(cin,searchInput);
			cout << endl << "Found Games" << endl;
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
			getline(cin,searchInput);
			cout << endl << "Found Games" << endl;
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
	addItemToCartPrint(inGames);//Also allows the user to add the game to cart or return to main menu
}

//Function to allow the user to exit the game
//Asks the user twice before closing the program
//Sleeps for 3 seconds to allow the user to read the text before closing
void Shopper::exitStore(list<Games*> &inGames)
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
			Sleep(3000);
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

//
//void Shopper::sortGames(list<Games*> &inGames)
//{
//	list<Games*>::iterator GameItor = CartOfGames.begin();
//	list<Games*>::iterator GameEndItor = CartOfGames.end();
//	
//	for(;GameItor!=GameEndItor;GameItor++)
//	{
//	inGames.sort(sortByTitle);
//	}
//	viewGames(inGames);
//}
//
//
//bool Shopper::sortByTitle(Games* const &lhs,Games* const &rhs)
//{	
//	if(lhs->getTitle()<rhs->getTitle())return true;
//	else if(lhs->getTitle()>rhs->getTitle()) return false;
//}
//


