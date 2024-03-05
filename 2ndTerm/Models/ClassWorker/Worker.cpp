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
	std::cout << "Имя: " << this->name << '\n' << "Фамилия: " << this->surname << '\n' << "Возраст: " << this->age << '\n' << "Должность: " << this->jobTitle << std::endl;
}


void FactoryWorker::AddInfo()
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

	std::cout << "Введите Должность: ";
	std::cin >> this->jobTitle;
}

std::string FactoryWorker::GetJobTitle()
{
	return this->jobTitle;
}

