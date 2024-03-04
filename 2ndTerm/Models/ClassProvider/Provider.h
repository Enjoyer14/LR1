#pragma once
#include <iostream>
#include "string"
#include "C:\Users\stass\OneDrive\Рабочий стол\2ndTerm\Models\ClassUser\User.h"

class Provider : public User
{
public:

	Provider();
	Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType);

	void PrintInfo() override;
	void AddInfo() override;

	friend int ReadProvidersInfoFromTxt(Provider* providers, int& count);

	std::string GetName();
	std::string GetSurname();
	int GetAge();
	std::string GetLogin();
	std::string GetPassword();
	std::string GetProductType();

private:

	std::string productType;
};