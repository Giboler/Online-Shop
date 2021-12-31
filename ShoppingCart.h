#pragma once
#include"Orders.h"
class ShoppingCart:public Orders 
{
public:
	void shoppingStart();
	void checkOut();
};