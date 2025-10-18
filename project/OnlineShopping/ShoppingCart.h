#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <vector>
#include <string>
#include "Product.h"

using namespace std;


class ShoppingCartItem {
protected:
	Product product;
	int quantity;
	double price;

public:
	ShoppingCartItem(Product prod, int qty, double thePrice);
	Product getProduct() const;
	int getQuantity() const;
	double getPrice() const;
	void addToQuantity(int qty);
	double lineItemTotalPrice();
};


class ShoppingCart {
protected:
	vector<ShoppingCartItem> items;

public:
	ShoppingCart();
	void addProductToCart(Product prod, int qty, double price);
	void updateProductQuantity();
	double cartTotalPrice();
	void removeProductFromCart();

	vector<ShoppingCartItem> getItems() const { return items; }	

}; // class ShoppingCart

#endif // !SHOPPINGCART_H
