#include "Worker.h"


FactoryWorker::FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle) : User(name, surname, age, login, password)
{
	this->jobTitle = jobTitle;
}

FactoryWorker::FactoryWorker() : User()
{
	this->jobTitle = " ";
}

void FactoryWorker::operator=(FactoryWorker other)
{
	this->name = other.name;
	this->surname = other.surname;
	this->age = other.age;
	this->login = other.login;
	this->password = other.password;
	this->jobTitle = other.jobTitle;
}


void FactoryWorker::PrintInfo()
{
	std::cout << "Name: " << this->name << '\n' << "Surname: " << this->surname << '\n' << "Age: " << this->age << '\n' << "Job title: " << this->jobTitle << std::endl;
}


void FactoryWorker::AddInfo()
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

	std::cout << "Enter job title: ";
	std::cin >> this->jobTitle;
}

std::string FactoryWorker::GetJobTitle()
{
	return this->jobTitle;
}

