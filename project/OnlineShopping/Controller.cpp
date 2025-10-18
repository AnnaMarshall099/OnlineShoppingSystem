#include "Constants.h"
#include "Controller.h"
#include "User.h"
#include <iostream>

using namespace std;

Controller::Controller()
{
}

void Controller::displayMainMenu()
{
    cout << "Please select from the following options:" << endl;
    cout << "1. View products" << endl;
    cout << "2. View cart" << endl;
    cout << "3. Checkout" << endl;
    cout << "4. Exit" << endl;
	cout << "5. Switch user (for testing)" << endl;
    cout << "Enter your choice: ";
}

void Controller::displayViewProductsMenu()
{
    cout << "Please select from the following options:" << endl;
    cout << "1. Select a product" << endl;
    cout << "2. View cart" << endl;
    cout << "3. Checkout" << endl;
    cout << "4. Return to main menu" << endl;
    cout << "Enter your choice: ";
}

void Controller::selectProductToAddToCart()
{
    int productId = 0;
    int quantity = 0;
    cout << "Enter the product ID to add to your cart: ";
    cin >> productId;
    cout << "Enter the quantity: ";
    cin >> quantity;

	Product p = Inventory::findProductById(productId);
	if (p.getName() == "")
    {
        cout << "    Product ID " << productId << " not found." << endl;
        return;
	}
	cart.addProductToCart(p, quantity, round((p.getPrice() * (1.0 - currentUser->getDiscount())) * 100) / 100.0);
    cout << "    Added product ID " << productId << " with quantity " << quantity << " to your cart." << endl;
}
void Controller::checkout(ShoppingCart* cart)
{
    if (cart->getItems().size() == 0)
    {
        cout << endl << "    Your cart is empty." << endl << endl;
        return;
    }
    cout << endl << "    Your total price is $" << cart->cartTotalPrice() << endl;
    cout << "    Do you want to confirm your purchase? (y/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
    {
        for (ShoppingCartItem item : cart->getItems())
        {
            Inventory::reduceQuantityFromInventory(item.getProduct(), item.getQuantity());
		}
        cout << "    Thank you for shopping with us!" << endl << endl;
        cart->emptyCart();
    }
    else
    {
        cout << "    Checkout cancelled." << endl;
    }
}
void Controller::displayCartContents(ShoppingCart cart)
{
    if (cart.getItems().size() == 0)
    {
        cout << endl << "    Your cart is empty." << endl << endl;
        return;
	}   
    cout << endl << "    ITEMS IN CART = " << cart.getItems().size() << ":" << endl;
    cout << "    +----------------------------------------------------------------+" << endl;
    cout << "    | Product ID   " << setw(14) << "Product Name" << "   Quantity   Price   Total Price   |" << endl;
    for (ShoppingCartItem item : cart.getItems())
    {
        cout << "    |     " << setw(2) << right << item.getProduct().getProductID();
        cout << "       " << setw(14) << left << item.getProduct().getName();
        cout << "      " << setw(2) << right << item.getQuantity();
        cout << "     " << setw(6) << item.getPrice();
        cout << "     " << setw(6) << item.getQuantity() * item.getPrice();
        cout << "      |" << endl;
    }
    cout << "    |                                                                |" << endl;
    cout << "    | Total Cart Price: $" << setw(44) << left << cart.cartTotalPrice() << setw(1) << "|" << endl;
    cout << "    +----------------------------------------------------------------+" << endl << endl;
}


void Controller::handleViewProductsMenu()
{
    int choice = 0;
    do
    {
        if (exitApp) return;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (DEBUG) cout << "Selecting a product to add to cart..." << endl;
            Inventory::printAllProducts();
            selectProductToAddToCart();
            Inventory::printAllProducts();
            displayViewProductsMenu();
			handleViewProductsMenu();
            break;
        case 2:
            if (DEBUG) cout << "Viewing cart..." << endl;
			displayCartContents(cart);
			displayViewProductsMenu();
			handleViewProductsMenu();
            break;
        case 3:
            if (DEBUG) cout << "Checking out..." << endl;
			checkout(&cart);
			displayMainMenu();
            handleMainMenu();
            break;
        case 4:
            if (DEBUG) cout << "Returning to main menu..." << endl;
			displayMainMenu();
            handleMainMenu();
            break;
        default:
            if (DEBUG) cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4 || exitApp);
}

void Controller::handleMainMenu()
{
    int choice = 0;
    do
    {
        if (exitApp) return;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (DEBUG) cout << "Viewing products..." << endl;
            //viewProducts();
            Inventory::printAllProducts();
            displayViewProductsMenu();
            handleViewProductsMenu();
            break;
        case 2:
            if (DEBUG) cout << "Viewing cart..." << endl;
            displayCartContents(cart);
            displayMainMenu();
            handleMainMenu();
            break;
        case 3:
            if (DEBUG) cout << "Checking out..." << endl;
            checkout(&cart);
            displayMainMenu();
            handleMainMenu();
            break;
        case 4:
            if (DEBUG) cout << "Exiting..." << endl;
			exitApp = true;
            break;
        case 5:
            if (DEBUG) cout << "Switching user..." << endl;
            currentUser->updateCart(cart);
            currentUser = User::getUser();
            cart = currentUser->getMyCart();
            displayMainMenu();
            handleMainMenu();
            break;
        default:
            if (DEBUG) cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4 || exitApp);
}

void Controller::run()
{
    cout << endl << "--- Anna's Online Shopping System ---" << endl << endl;
    currentUser = User::getUser();
    cart = currentUser->getMyCart();
    displayMainMenu();
    handleMainMenu();
}
