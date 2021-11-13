#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
private:
    string itemName;
    int itemPrice;
    int itemQuantity;
    string itemDescription;

public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);

    // Declare mutators
    void SetName();
    void SetName(string name);
    void SetPrice();
    void SetPrice(int price);
    void SetQuantity();
    void SetQuantity(int quantity);
    void SetDescription();
    void SetDescription(string description);

    // Declare accessors
    string GetName();
    int GetPrice();
    int GetQuantity();
    string GetDescription();

    void PrintItemCost();
    void PrintItemDescription();
};

#endif