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
	std::cout << "���: " << this->name << '\n' << "�������: " << this->surname << '\n' << "�������: " << this->age << '\n' << "��� ���������: " << this->productType << std::endl;
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