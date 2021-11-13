#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

// Default constructor
ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

// Parametrized constructor
ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

// Gets the customer name
string ShoppingCart::GetCustomerName() {
    return customerName;
}

// Gets the date
string ShoppingCart::GetDate() {
    return currentDate;
}

// Adds the given item to the cartItems vector
void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

// Removes the given item from the cartItems vector
void ShoppingCart::RemoveItem(string name) {
    int numCount = 0;
    int position = 0;

    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == name) {
            position = i;
            numCount++;
        }
    }

    // If the cart is empty, nothing will be removed
    if (numCount == 0) {
        cout << "Item not found in cart. Nothing removed." << endl;
    } else {
        cartItems.erase(cartItems.begin() + position);
    }
    cout << endl;
}

// Modifies the quantity of the given item
void ShoppingCart::ModifyItem(ItemToPurchase item) {
    int count = 0;

    for (int i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            cartItems.at(i).SetQuantity(item.GetQuantity());
            count++;
        }
    }
    if (count == 0) {
        cout << "Item not found in cart. Nothing modified." << endl << endl;
    }
}

// Gets the number of items in the shopping cart
int ShoppingCart::GetNumItemsInCart() {
    return cartItems.size();
}

// Finds and returns the total cost of all the items that are in the shopping cart
int ShoppingCart::GetCostOfCart() {
    int totalCost = 0;
    int itemCost;
    for (int i = 0; i < cartItems.size(); i++) {
        itemCost = cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice();
        totalCost += itemCost;
    }
    return totalCost;
}

/* Outputs all of the items that are in the cartItems vector along with their quantities and prices.
   Will also print the total number of items and the total price of everything in the shopping cart. */
void ShoppingCart::PrintTotal() {
    int totalCost = 0;
    int itemCost;
    int numItems = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    for (int i =0; i < cartItems.size(); i++) {
        numItems += cartItems.at(i).GetQuantity();
    }
    cout << "Number of Items: " << numItems << endl << endl;
    if (cartItems.size() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    for (int i =0; i < cartItems.size(); i++) {
        cartItems.at(i).PrintItemCost();
        itemCost = cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice();
        totalCost += itemCost;
    }
    cout << endl << "Total: $" << totalCost << endl << endl;
}

// Outputs the description of each item in the cartItems vector.
void ShoppingCart::PrintDescription() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (int i =0; i < cartItems.size(); i++) {
        cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
    }
    cout << endl;
}
