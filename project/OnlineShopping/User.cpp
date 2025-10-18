#include "User.h"
#include "Address.h"
#include "ShoppingCart.h"

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

vector<User*> User::allUsers;

void User::addAllUsers() {
    User* user1 = new User();
    user1->setUsername("Bella");
    user1->setPassword("pass1");
    allUsers.push_back(user1);

    VIPUser* vipUser = new VIPUser();
    vipUser->setUsername("AnnaVIP");
    vipUser->setPassword("vippass");
    allUsers.push_back(vipUser);

    PremiumUser* premiumUser = new PremiumUser();
    premiumUser->setUsername("DavePR");
    premiumUser->setPassword("premiumpass");
    allUsers.push_back(premiumUser);
}

string User::getPasswordWindows()
{
    string password;
    char ch;
    while ((ch = _getch()) != '\r')    // carriage return
    {
        if (ch == '\b')         // backspace
        {
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password += ch;
            cout << '*';
        }
    }
    cout << '\n';
    return password;
}

User* User::getUser() {
    string uname;
    string pword;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    pword = getPasswordWindows();
    for (User* u : allUsers) {
        if (u->getUsername() == uname ){ //&& u.getPassword() == pword) {
            return u;
        }
    }
    cout << "Invalid username or password. Please try again." << endl;
    return getUser();
}

void User::updateCart(ShoppingCart cart) 
{
    myCart = cart;
}

ShoppingCart User::getMyCart() const {
    return myCart;
}
string User::getUsername() const {
    return username;
}

void User::setUsername(const string& newUsername) {
    username = newUsername;
}

string User::getPassword() const {
    return password;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

double User::getDiscount() const {
    return 0.00;
}

double VIPUser::getDiscount() const {
    return 0.10;
}

double PremiumUser::getDiscount() const {
    return 0.20;
}