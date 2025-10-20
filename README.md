# Online Shopping System

Video Demo: https://youtu.be/ja4XhP-t1Aw

A simple online shopping system using C++, where users can browse products, add them to their shopping cart, and complete purchases.

This project is an online shopping system. It allows users to browse products, add them to their shopping cart, and complete purchases. It is console-based with simulated concurrent users. To simulate concurrency, a “Switch User” menu item is provided to change to a different user. It is important to note that there are three valid usernames to enter this system: “Bella”, “AnnaVIP”, and “DavePR”. Any password will do.

The project is broken into several logical classes, including Inventory, Product, ShoppingCart, ShoppingCartItem, User, and, perhaps most importantly, a Controller class. Breaking up the system into individual files per class helped me to keep the code clean, organize it logically, and debug quickly. For larger projects, separate files also allow for efficient collaboration. 
There are two User files: User.h and User.cpp. The User.h file declares three different classes: User, VIPUser, and PremiumUser. The VIPUser and the PremiumUser are inherited classes of the parent class User. The VIPUser and PremiumUser receive discounts. User.h file defines the classes but does not describe how they behave. The User.cpp file fills that gap and implements the methods declared in User.h. A login function checks for a matching username and returns the corresponding user (regular, VIP, or Premium). User receives no discount, VIPUser receives a 10% discount, and PremiumUser receives a 20% discount.
There are also two Product files, Product.h and Product.cpp. The header file defines a Product class with attributes including product ID, company, name, description, and price. It includes a constructor and getter/setter methods for each attribute. The Product.cpp file implements the methods declared in the Product.h header file. It implements a constructor that initializes an instance object, and it also implements getter and setter methods for each attribute. 

The Inventory.h file declares one class: Inventory. The Inventory class was added to ensure the Products class code remained clean and was much more efficient than trying to combine these classes into one class. Inventory defines methods including addAllProducts(), addProductToInventory(Product p, int quantity), removeProductFromInventory(Product p), reduceQuantityFromInventory(Product p, int byHowMany), findProductById(int productID), and printAllProducts(). ProductAndQuanity is a structure that contains two fields: Product p and int quantity, allowing the struct to match a product with its stock quantity in the inventory. The Inventory.cpp file describes the behaviors of each of these functions and implements the methods.

ShoppingCart.h defines two classes: ShoppingCartItem and ShoppingCart, but does not describe their behavior. ShoppingCartItem lists methods to get product details, update quantity, and calculate the total price for that line item, while ShoppingCart lists methods to add product line items, update quantities, remove items, and calculate the total price of the cart. ShoppingCart.cpp implements the methods declared in the header file.

Address.h defines an Address class with protected fields for name, street addresses, city, state, zip code, and country. It declares getter methods for address1 and address2. Address.cpp implements the methods declared in the header file. 

The Controller.h file is a header file. It defines a Controller class that runs the main shopping app. The user interface loop is in Controller. It allows the program to continuously run. The Controller class declares various methods including run(), displayCartContents(ShoppingCart cart), viewProducts(), selectProductToAddToCart(), checkout(ShoppingCart cart), displayMainMenu(), displayProducts(), and displayViewProductsMenu(). The Controller.cpp file implements the Controller class, which manages the main menu, product browsing, cart handling, and checkout process in the shopping system. It allows users to add products to their cart with discounts applied, view cart contents, and complete purchases while updating inventory. The program runs in a loop until the user chooses to exit or switch accounts.
OnlineShopping.cpp is the main file that sets up and launches the shopping application. It allows users to enter into the system. If the DEBUG is true, it prints all inventory items and runs the shopping cart test. It creates a Controller object and calls its run() method to launch the main application. 

The online shopping system utilized a variety of files to ensure the code remained clean and easy to understand. There were several different design choices for this system. Separating the Product class and the Inventory class ensured encapsulation. The controller handled the user interface and customer inputs, ensuring the system ran smoothly. This allowed the system to properly perform its job and enable users to browse products, add them to their shopping cart, and complete purchases









