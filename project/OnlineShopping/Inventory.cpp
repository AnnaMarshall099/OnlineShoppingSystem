#include "Inventory.h"
#include "Product.h"
#include <iostream> 
#include <iomanip>
#include <algorithm> // for std::remove 
using namespace std;

vector<Inventory::ProductAndQuantity> Inventory::allProducts;

void Inventory::addProductToInventory(Product p, int quantity) {
    ProductAndQuantity pq;
    pq.p = p;
    pq.quantity = quantity;
    allProducts.push_back(pq);
}

void Inventory::removeProductFromInventory(Product p)
{
	// Find the product in allProducts and remove it
    for (auto it = allProducts.begin(); it != allProducts.end(); ++it)
    {
        if (it->p.getCompany() == p.getCompany() && it->p.getName() == p.getName())
        {
            allProducts.erase(it);
            break;
        }
    }
}

void Inventory::reduceQuantityFromInventory(Product p, int byHowMany)
{
    // Find the product in allProducts and reduce its quantity 
    for (ProductAndQuantity& invItem : allProducts)
    {
        if (invItem.p.getCompany() == p.getCompany() && invItem.p.getName() == p.getName())
        {
            invItem.quantity -= byHowMany;
            if (invItem.quantity < 0)
                invItem.quantity = 0;
            break;
        }
    }
}

void Inventory::addAllProducts()
{
    int productID = 0;
    Product p1 = Product(++productID, "Head & Shoulders", "Shampoo", "The world's best shampoo!", 2.89);
    addProductToInventory(p1, 101);
    reduceQuantityFromInventory(p1, 1);
    Product p2 = Product(++productID, "Head & Shoulders", "Conditioner", "It makes your hair silky soft!", 2.99);
    addProductToInventory(p2, 100);
    Product p3 = Product(++productID, "Johnson & Johnson", "Body Wash", "Pine scented", 3.49);
    addProductToInventory(p3, 100);
    Product p4 = Product(++productID, "Johnson & Johnson", "Anti-bacterial Soap", "Lavender scened", 3.49);
    addProductToInventory(p4, 100);
    Product p5 = Product(++productID, "Colgate", "Toothpaste", "Flouride free", 1.57);
    addProductToInventory(p5, 100);
}

void Inventory::printAllProducts(double discount)
{
    cout << endl;
    for (ProductAndQuantity pq : allProducts) 
    {
        cout << "    " << left << pq.p.getProductID() << ": " << setw(22) << (pq.p.getCompany() + "'s ");
        cout << setw(20) << pq.p.getName() << " $" << fixed << setprecision(2) << round(pq.p.getPrice() * (1.0 - discount) * 100) / 100.0 << "     [quantity remaining = " << setw(3) << right << pq.quantity << "]" << endl;
    }
    cout << endl;
}

Product Inventory::findProductById(int productID)
{
    for (ProductAndQuantity pq : allProducts)
    {
        if (pq.p.getProductID() == productID)
            return pq.p;
    }

    return Product();
}
