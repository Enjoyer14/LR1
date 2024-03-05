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
	std::cout << "���: " << this->name << '\n' << "�������: " << this->surname << '\n' << "�������: " << this->age << '\n' << "��� ���������: " << this->productType << std::endl << std::endl;
}

void Provider::AddInfo()
{
	std::cout << "������� ���: ";
	std::cin >> this->name;

	std::cout << "������� �������: ";
	std::cin >> this->surname;

	std::cout << "������� �������: ";
	std::cin >> this->age;
	std::cin.ignore(32767, '\n');

	std::cout << "������� �����: ";
	std::cin >> this->login;

	std::cout << "������� ������: ";
	std::cin >> this->password;

	std::cout << "������� ��� ���������: ";
	std::cin >> this->productType;
}

std::string Provider::GetProductType()
{
	return this->productType;
}