// InventoryManager.cpp
#include "InventoryManager.h"
#include <iostream>
#include <algorithm>

using namespace std;

void InventoryManager::addProduct() {
    string name;
    int id, quantity;
    double price;

    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter product ID: ";
    cin >> id;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter stock quantity: ";
    cin >> quantity;

    Product newProduct(name, id, price, quantity);
    inventory.push_back(newProduct);
    cout << "Product added successfully!" << endl;
}

void InventoryManager::displayInventory() const {
    if (inventory.empty()) {
        cout << "No products in inventory." << endl;
        return;
    }

    for (const auto& product : inventory) {
        product.display();
    }
}

void InventoryManager::lowStockNotification(int threshold) const {
    bool lowStockFound = false;
    cout << "\nLow Stock Products (Below " << threshold << " units):" << endl;

    for (const auto& product : inventory) {
        if (product.getStockQuantity() < threshold) {
            cout << product.getName() << " (ID: " << product.getProductId()
                 << ") - " << product.getStockQuantity() << " units left." << endl;
            lowStockFound = true;
        }
    }

    if (!lowStockFound) {
        cout << "No products are below the low stock threshold." << endl;
    }
}

void InventoryManager::sellProduct() {
    int productId, quantity;
    cout << "Enter product ID to sell: ";
    cin >> productId;

    auto it = find_if(inventory.begin(), inventory.end(), [productId](const Product& p) {
        return p.getProductId() == productId;
    });

    if (it != inventory.end()) {
        cout << "Enter quantity to sell: ";
        cin >> quantity;
        it->sellProduct(quantity);
        cout << "Sale successful!" << endl;
    } else {
        cout << "Product ID not found!" << endl;
    }
}

void InventoryManager::purchaseProduct() {
    int productId, quantity;
    cout << "Enter product ID to purchase: ";
    cin >> productId;

    auto it = find_if(inventory.begin(), inventory.end(), [productId](const Product& p) {
        return p.getProductId() == productId;
    });

    if (it != inventory.end()) {
        cout << "Enter quantity to purchase: ";
        cin >> quantity;
        it->updateStock(quantity);
        cout << "Purchase successful!" << endl;
    } else {
        cout << "Product ID not found!" << endl;
    }
}

void InventoryManager::deleteProduct() {
    int productId;
    cout << "Enter product ID to delete: ";
    cin >> productId;

    auto it = find_if(inventory.begin(), inventory.end(), [productId](const Product& p) {
        return p.getProductId() == productId;
    });

    if (it != inventory.end()) {
        char confirmation;
        cout << "Are you sure you want to delete the product (ID: " << productId << ")? (Y/N): ";
        cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y') {
            inventory.erase(it);
            cout << "Product deleted successfully!" << endl;
        } else {
            cout << "Product deletion canceled." << endl;
        }
    } else {
        cout << "Product ID not found!" << endl;
    }
}
