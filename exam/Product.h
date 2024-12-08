#pragma once
// Product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    int productId;
    double price;
    int stockQuantity;

public:
    Product(std::string name, int id, double price, int quantity);

    std::string getName() const;
    int getProductId() const;
    double getPrice() const;
    int getStockQuantity() const;

    void setStockQuantity(int quantity);
    void updateStock(int quantity);
    void sellProduct(int quantity);

    void display() const;
};

#endif // PRODUCT_H
