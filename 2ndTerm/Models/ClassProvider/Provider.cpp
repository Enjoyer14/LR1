#include "Provider.h"

Provider::Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType) : User(name, surname, age, login, password)
{
	this->productType = productType;
}

Provider::Provider() : User()
{
	this->name = " ";

}

void Provider::operator=(Provider other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->login = other.login;
	this->password = other.password;
	this->productType = other.productType;
}

void Provider::PrintInfo()
{
	std::cout << "Name: " << this->name << '\n' << "Surname: " << this->surname << '\n' << "Age: " << this->age << '\n' << "Product type: " << this->productType << std::endl << std::endl;
}

void Provider::AddInfo()
{
	std::cout << "Enter name: ";
	std::cin >> this->name;

	std::cout << "Enter surname: ";
	std::cin >> this->surname;

	std::cout << "Enter age: ";
	std::cin >> this->age;
	std::cin.ignore(32767, '\n');

	std::cout << "Enter login: ";
	std::cin >> this->login;

	std::cout << "Enter password: ";
	std::cin >> this->password;

	std::cout << "Enter product type: ";
	std::cin >> this->productType;
}

std::string Provider::GetProductType()
{
	return this->productType;
}