#include "Product.h"


Product::Product(std::string productType, std::string productTitle, double cost, int quantity)
{
	this->productType = productType;
	this->productTitle = productTitle;
	this->cost = cost;
	this->quantity = quantity;
}

void Product::Print() {
	std::cout << "Тип продукта: " << productType << '\n' << "Название: " << productTitle << '\n' << "Цена: " << cost << '\n' << "Количество: " << quantity << std::endl;
}

void Product::SetCost(double cost)
{
	this->cost = cost;
}

void Product::SetQuantity(int quantity)
{
	this->quantity = quantity;
}