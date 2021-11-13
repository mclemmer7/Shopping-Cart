#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

// Default constructor
ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

// Parametrized constructor
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

// Define mutators
void ItemToPurchase::SetName() {
    itemName = "none";
}
void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice() {
    itemPrice = 0;
}
void ItemToPurchase::SetPrice(int price) {
    itemPrice = price;
}

void ItemToPurchase::SetQuantity() {
    itemQuantity = 0;
}
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

void ItemToPurchase::SetDescription() {
    itemDescription = "none";
}
void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

// Define accessors
string ItemToPurchase::GetName() {
    return itemName;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

// Outputs the item, quantity, price, and total price for an item.
void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}

// Outputs the description for an item.
void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}