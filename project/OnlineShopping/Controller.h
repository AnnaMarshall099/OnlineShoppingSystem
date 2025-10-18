#ifndef  CONTROLLER_H
#define  CONTROLLER_H
#include "Product.h"
#include "Inventory.h"
#include "ShoppingCart.h"
#include "User.h"
#include "Constants.h"
#include <iostream>	
#include <string>
#include <iomanip>
using namespace std;	


class Controller
{
public:
	static Inventory inventory;

	Controller();
	void run();
	static void displayCartContents(ShoppingCart cart);

private:
	bool exitApp = false;
	User* currentUser;
	ShoppingCart cart = ShoppingCart();
	void handleMainMenu();
	void handleViewProductsMenu();
	void selectProductToAddToCart();
	void checkout(ShoppingCart* cart);
	void displayMainMenu();
	void displayViewProductsMenu();
};

#endif