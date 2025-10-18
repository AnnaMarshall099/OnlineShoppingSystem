#ifndef USER_H
#define USER_H  

#include <iostream>
#include <vector>
#include <string>
#include "Address.h"
#include "ShoppingCart.h"
using namespace std;

class User {
protected:
    string username;
    string password;
    string name;
    string email;
    Address billingAddress;
    Address shippingAddress;
    ShoppingCart myCart;

public:
    string getUsername() const;
    void setUsername(const string& newUsername);

    string getPassword() const;
    void setPassword(const string& newPassword);

	void updateCart(ShoppingCart cart);
    ShoppingCart getMyCart() const;

    static User* getUser();
	static vector<User*> allUsers;
    static void addAllUsers();
	virtual double getDiscount() const;
};

class VIPUser : public User {
   public:
	   double getDiscount() const;
};

// --- PremiumUser Class ---
class PremiumUser : public User {
  public:
	  double getDiscount() const;
};

#endif // !USER_H
