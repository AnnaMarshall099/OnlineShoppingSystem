#include "ShoppingCart.h"

ShoppingCartItem::ShoppingCartItem(Product prod, int qty, double thePrice)
{
	product = prod;
	quantity = qty;
	price = thePrice;
}

Product ShoppingCartItem::getProduct() const {
	return product;
}

int ShoppingCartItem::getQuantity() const {
	return quantity;
}

double ShoppingCartItem::getPrice() const {
	return price;
}
void ShoppingCartItem::addToQuantity(int qty) {
	quantity += qty;
}
double ShoppingCartItem::lineItemTotalPrice() {
	return 125.00;
}



ShoppingCart::ShoppingCart() 
{
}
void ShoppingCart::addProductToCart(Product prod, int qty, double price)
{
	//check if product already exists in cart at this price
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (it->getProduct().getProductID() == prod.getProductID() && it->getPrice() == price)
		{
			it->addToQuantity(qty);
			return;
		}
	}
	ShoppingCartItem item = ShoppingCartItem(prod, qty, price);
	items.push_back(item);
}

void ShoppingCart::emptyCart()
{
	items.clear();
}
	
double ShoppingCart::cartTotalPrice() 
{ 
	double total = 0.0;
	for (auto it = items.begin(); it != items.end(); ++it)
		total += it->getPrice() * it->getQuantity();
	return total;
}


void ShoppingCart::updateProductQuantity() {}
void ShoppingCart::removeProductFromCart() {}
