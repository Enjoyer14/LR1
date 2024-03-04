#include "Provider.h"

Provider::Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType) : User(name, surname, age, login, password)
{
	this->productType = productType;
}

Provider::Provider() : User()
{
	this->name = " ";

}

void Provider::PrintInfo()
{
	std::cout << "Имя: " << this->name << '\n' << "Фамилия: " << this->surname << '\n' << "Возраст: " << this->age << '\n' << "Тип продукции: " << this->productType << std::endl;
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

std::string Provider::GetName()
{
	return this->name;
}

std::string Provider::GetSurname()
{
	return this->surname;
}

int Provider::GetAge()
{
	return this->age;
}

std::string Provider::GetLogin()
{
	return this->login;
}

std::string Provider::GetPassword()
{
	return this->password;
}

std::string Provider::GetProductType()
{
	return this->productType;
}