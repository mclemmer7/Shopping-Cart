#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

// Outputs the menu with the options that the user can select.
void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
}

// Executes the option that was selected by the user.
void ExecuteMenu(char option, ShoppingCart& theCart) {
    ItemToPurchase item;
    string description;
    int itemPrice;
    int itemQuantity;

    switch (option) {
        case 'a': {
            //Add item
            string name;
            cin.ignore();
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name);
            item.SetName(name);

            cout << "Enter the item description:" << endl;
            getline(cin, description);
            item.SetDescription(description);

            cout << "Enter the item price:" << endl;
            cin >> itemPrice;
            item.SetPrice(itemPrice);

            cout << "Enter the item quantity:" << endl << endl;
            cin >> itemQuantity;
            item.SetQuantity(itemQuantity);

            theCart.AddItem(item);
            break;
        }
        case 'd': {
            //remove item
            string itemName;
            cin.ignore();
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, itemName);

            theCart.RemoveItem(itemName);
            break;
        }
        case 'c': {
            //change item quantity
            string name2;

            cin.ignore();
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, name2);
            item.SetName(name2);

            cout << "Enter the new quantity:" << endl;
            cin >> itemQuantity;
            item.SetQuantity(itemQuantity);
            theCart.ModifyItem(item);
            break;
        }
        case 'i': {
            // Output descriptions
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            theCart.PrintDescription();
            break;
        }
        case 'o': {
            // output shopping cart
            cout << "OUTPUT SHOPPING CART" << endl;
            theCart.PrintTotal();
            break;
        }
    }
}

int main() {
    string date;
    string name;
    char option;

    cout << "Enter customer's name:" << endl;
    getline(cin, name);
    cout << "Enter today's date:" << endl << endl;
    getline(cin, date);

    cout << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl << endl;
    ShoppingCart theCart = ShoppingCart(name, date);

    PrintMenu();
    cout << "Choose an option:" << endl;
    cin >> option;

    // The program will keep running until the user enters 'q' to quit
    while (option != 'q') {
        if (option == 'a' || option == 'd' || option == 'c' || option == 'i' || option == 'o') {
            ExecuteMenu(option, theCart);
            PrintMenu();
            cout << "Choose an option:" << endl;
            cin >> option;
        } else if (option == 'q') {
            break;
        }
        else {
            cout << "Choose an option:" << endl;
            cin >> option;
        }
    }
    return 0;
}
