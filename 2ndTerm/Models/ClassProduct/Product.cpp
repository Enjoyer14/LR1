#include "Product.h"


Product::Product(std::string productType, std::string productTitle, double cost, int quantity)
{
	this->productType = productType;
	this->productTitle = productTitle;
	this->cost = cost;
	this->quantity = quantity;
}

Product::Product(){
	
}

void Product::Print() {
	std::cout << "Product type: " << productType << '\n' << "Product title: " << productTitle << '\n' << "Cost: " << cost << '\n' << "Quantity: " << quantity << std::endl;
}

void Product::SetCost(double cost)
{
	this->cost = cost;
}

void Product::SetQuantity(int quantity)
{
	this->quantity = quantity;
}

void Product::AddInfo()
{
	std::cout << "Enter type: ";
	std::cin >> this->productType;

	std::cout << "Enter product title: ";
	std::cin >> this->productTitle;

	std::cout << "Enter cost: ";
	std::cin >> this->cost;
	std::cin.ignore(32767, '\n');

	std::cout << "Enter quantity: ";
	std::cin >> this->quantity;
	std::cin.ignore(32767, '\n');

}