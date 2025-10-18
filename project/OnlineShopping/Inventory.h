#ifndef INVENTORY_H
#define INVENTORY_H 

#include <vector>
#include "Product.h"
using namespace std;

class Inventory {
protected:

public:
    struct ProductAndQuantity {
        Product p;
        int quantity;
    };

    static vector<ProductAndQuantity> allProducts;
    static void addAllProducts();
    static void addProductToInventory(Product p, int quantity);
    static void removeProductFromInventory(Product p);
    static void reduceQuantityFromInventory(Product p, int byHowMany);
    static Product findProductById(int productID);
    static void printAllProducts(double discount);
}; // class Inventory

#endif // !INVENTORY_H
