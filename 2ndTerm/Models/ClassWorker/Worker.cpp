#include "Worker.h"


FactoryWorker::FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle) : User(name, surname, age, login, password)
{
	this->jobTitle = jobTitle;
}

FactoryWorker::FactoryWorker() : User()
{
	this->jobTitle = " ";
}

void FactoryWorker::PrintInfo()
{
	std::cout << "���: " << this->name << '\n' << "�������: " << this->surname << '\n' << "�������: " << this->age << '\n' << "���������: " << this->jobTitle << std::endl;
}


void FactoryWorker::AddInfo()
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

	std::cout << "������� ���������: ";
	std::cin >> this->jobTitle;
}

std::string FactoryWorker::GetName()
{
	return this->name;
}

std::string FactoryWorker::GetSurname()
{
	return this->surname;
}

int FactoryWorker::GetAge()
{
	return this->age;
}

std::string FactoryWorker::GetLogin()
{
	return this->login;
}

std::string FactoryWorker::GetPassword()
{
	return this->password;
}

std::string FactoryWorker::GetJobTitle()
{
	return this->jobTitle;
}

