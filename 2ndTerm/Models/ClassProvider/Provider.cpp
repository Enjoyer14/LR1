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
	std::cout << "Имя: " << this->name << '\n' << "Фамилия: " << this->surname << '\n' << "Возраст: " << this->age << '\n' << "Тип продукции: " << this->productType << std::endl << std::endl;
}

void Provider::AddInfo()
{
	std::cout << "Введите Имя: ";
	std::cin >> this->name;

	std::cout << "Введите Фамилию: ";
	std::cin >> this->surname;

	std::cout << "Введите Возраст: ";
	std::cin >> this->age;
	std::cin.ignore(32767, '\n');

	std::cout << "Введите Логин: ";
	std::cin >> this->login;

	std::cout << "Введите Пароль: ";
	std::cin >> this->password;

	std::cout << "Введите Тип продукции: ";
	std::cin >> this->productType;
}

std::string Provider::GetProductType()
{
	return this->productType;
}