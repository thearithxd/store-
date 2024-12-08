#pragma once
// InventoryManager.h
#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Product.h"
#include <vector>

class InventoryManager {
private:
    std::vector<Product> inventory;

public:
    void addProduct();
    void displayInventory() const;
    void lowStockNotification(int threshold) const;
    void sellProduct();
    void purchaseProduct();
    void deleteProduct();
};

#endif // INVENTORYMANAGER_H
