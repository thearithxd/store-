// main.cpp
#include <iostream>
#include "User.h"
#include "Product.h"
#include "InventoryManager.h"

using namespace std;

int main() {
    string enteredUsername, enteredPassword;
    User admin;  // By default, uses username "rith" and password "123"
    InventoryManager manager;

    // User login
    cout << "Enter Username: ";
    cin >> enteredUsername;
    cout << "Enter Password: ";
    cin >> enteredPassword;

    if (admin.authenticate(enteredUsername, enteredPassword)) {
        cout << "Login successful!" << endl;

        int choice;
        const int threshold = 30;
        while (true) {
            cout << "\nInventory Management System" << endl;
            cout << "1. Add Product" << endl;
            cout << "2. Display Inventory" << endl;
            cout << "3. Sell Product" << endl;
            cout << "4. Purchase Product" << endl;
            cout << "5. Low Stock Notification" << endl;
            cout << "6. Generate Report" << endl;
            cout << "7. Delete Product" << endl;
            cout << "8. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                manager.addProduct();
                break;
            case 2:
                manager.displayInventory();
                break;
            case 3:
                manager.sellProduct();
                break;
            case 4:
                manager.purchaseProduct();
                break;
            case 5:
                manager.lowStockNotification(threshold);
                break;
            case 6:
                manager.displayInventory();
                break;
            case 7:
                manager.deleteProduct();
                break;
            case 8:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
    else {
        cout << "Login failed! Incorrect username or password." << endl;
    }

    return 0;
}
