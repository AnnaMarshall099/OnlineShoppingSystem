#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
protected:
    int productID;
    string company;
    string name;
    string description;
    double price;

public:
	Product() : productID(0), company(""), name(""), description(""), price(0.0) {}
	Product(int productID, string company, string name, string description, double price);

    int getProductID() const;
    void setProductID(const int& newProductID);

    string getCompany() const;
    void setCompany(const string& newCompany);

    string getName() const;
    void setName(const string& newName);

    string getDescription() const;
    void setDescription(const string& newDescription);

    double getPrice() const;
    void setPrice(double newPrice);

};
#endif
