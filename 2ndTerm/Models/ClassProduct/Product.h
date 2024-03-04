#pragma once
#include <string>
#include <iostream>

class Product
{
public:

	Product(std::string productType, std::string productTitle, double cost, int quantity);


	void Print();

	double GetCost() { return this->cost; }
	int GetQuantity() { return this->quantity; }

	void SetCost(double cost);
	void SetQuantity(int quantity);



private:

	std::string productType;
	std::string productTitle;
	double cost;
	int quantity;

};