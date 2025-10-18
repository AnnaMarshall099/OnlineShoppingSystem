#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
protected:
    string name;
    string address1, address2, city, state, zip, country;

public:
    string getAddress1() const;
    string getAddress2() const;

};

#endif



