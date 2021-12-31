#pragma once
#include"Customer.h"
class Products:public Customer
{
public:
    string line;
    int productID;
    string productName;
    string productType;
    string productSpecification;
    string productMaker;
    int productCost;
    void setProduct();
    void setID();
    void addProduct();
    void pack();
    void unpack();
    void display();
    bool searchProducts(string n);
    void displayAll();
    void deleteProduct(string n);
    void updateProduct();
    void productStart();
};

