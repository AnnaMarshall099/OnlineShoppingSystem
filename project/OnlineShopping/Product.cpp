#include "Product.h"

Product::Product(int productID, string company, string name, string description, double price)
{
    this->productID = productID;
    this->company = company;
    this->name = name;
    this->description = description;
	this->price = price;
}

// Getter and Setter for productID
int Product::getProductID() const {
    return productID;
}
void Product::setProductID(const int& newProductID) {
    productID = newProductID;
}

// Getter and Setter for company
string Product::getCompany() const {
    return company;
}
void Product::setCompany(const string& newCompany) {
    company = newCompany;
}

// Getter and Setter for name
string Product::getName() const {
    return name;
}
void Product::setName(const string& newName) {
    name = newName;
}

// Getter and Setter for description
string Product::getDescription() const {
    return description;
}
void Product::setDescription(const string& newDescription) {
    description = newDescription;
}

// Getter and Setter for price
double Product::getPrice() const {
    return price;
}
void Product::setPrice(double newPrice) {
    price = newPrice;
}
