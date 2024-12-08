// Product.cpp
#include "Product.h"
#include <iostream>
#include <iomanip>  // For formatting prices

using namespace std;

Product::Product(string name, int id, double price, int quantity)
    : name(name), productId(id), price(price), stockQuantity(quantity) {
}

string Product::getName() const { return name; }
int Product::getProductId() const { return productId; }
double Product::getPrice() const { return price; }
int Product::getStockQuantity() const { return stockQuantity; }

void Product::setStockQuantity(int quantity) { stockQuantity = quantity; }

void Product::updateStock(int quantity) { stockQuantity += quantity; }

void Product::sellProduct(int quantity) {
    if (stockQuantity >= quantity) {
        stockQuantity -= quantity;
    }
    else {
        cout << "Not enough stock to sell " << quantity << " units of " << name << endl;
    }
}

void Product::display() const {
    cout << "Product Name: " << name << ", Product ID: " << productId
        << ", Price: $" << fixed << setprecision(2) << price
        << ", Stock Quantity: " << stockQuantity << endl;
}
