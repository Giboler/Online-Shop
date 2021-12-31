#pragma once
#include "Products.h"
class Orders:public Products
{
public:
    void placeOrder();
    void viewOrders();
    void removeOrder(string n);
    void calculateCost();
};