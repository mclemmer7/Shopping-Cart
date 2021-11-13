#ifndef MODULE_6_LAB_SHOPPINGCART_H
#define MODULE_6_LAB_SHOPPINGCART_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"

class ShoppingCart {
private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;

public:
    // Default constructor
    ShoppingCart();
    // Parametrized constructor
    ShoppingCart(string name, string date);

    // Declare accessors
    string GetCustomerName();
    string GetDate();
    void AddItem(ItemToPurchase item);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescription();

};


#endif //MODULE_6_LAB_SHOPPINGCART_H
