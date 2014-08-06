
#include <iostream>
#include "Product.h"
#include "Games.h"
#include "Shop.h"

using namespace std;

void main()
{
	Shop mainShop;
	mainShop.loginScreen();
	Games game1("Thief","A game about killing people in the dark if possible","Stealth","Square Enix","Square Enix",1,325,124,154,600,1023,55.99,2014);
	game1.printProdInfo();

}



