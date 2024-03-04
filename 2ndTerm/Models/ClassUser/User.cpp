#include "User.h"

User::User(std::string name, std::string surname, int age, std::string login, std::string password)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->login = login;
	this->password = password;
}

User::User()
{
	this->name = " ";
	this->surname = " ";
	this->age = 0;
	this->login = " ";
	this->password = " ";
}