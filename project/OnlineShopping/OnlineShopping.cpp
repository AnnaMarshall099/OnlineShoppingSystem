#include "Constants.h"
#include "Controller.h"
#include "Inventory.h"
#include "ShoppingCart.h"
#include "User.h"
#include <iostream>
using namespace std;

void testInventory()
{
}

void testShoppingCart()
{
	ShoppingCart cart = ShoppingCart();
	int productID = 0;
	Product p1a = Product(++productID, "Johnson & Johnson", "Shampoo", "The world's best shampoo!", 2.89);
	cart.addProductToCart(p1a, 1, 2.89);
	Product p1b = Product(productID, "Johnson & Johnson", "Shampoo", "The world's best shampoo!", 2.89);
	cart.addProductToCart(p1b, 2, 2.89);
	Product p1c = Product(productID, "Johnson & Johnson", "Shampoo", "The world's best shampoo!", 2.89);
	cart.addProductToCart(p1c, 4, 2.44);
	Product p2 = Product(++productID, "Johnson & Johnson", "Conditioner", "It makes your hair silky soft!", 2.99);
	cart.addProductToCart(p2, 2, 0.01);
	Product p3 = Product(++productID, "Johnson & Johnson", "Body Wash", "Pine scented", 3.49);
	cart.addProductToCart(p3, 3, 3.49);

	Controller::displayCartContents(cart);
}

int main()
{
	Inventory::addAllProducts();
	User::addAllUsers();
	if (DEBUG)
	{
		Inventory::printAllProducts(0.00);
		testShoppingCart();
	}
	Controller app = Controller();
	app.run();
	return 0;
}
