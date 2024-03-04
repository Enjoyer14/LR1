#pragma once
#include <string>
#include <iostream>
#include "C:\Users\stass\OneDrive\Рабочий стол\2ndTerm\Models\ClassUser\User.h"


class FactoryWorker : public User
{
public:

	FactoryWorker();
	FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle);
	
	void PrintInfo () override;
	void AddInfo() override;

	friend int ReadWorkersInfoFromTxt(FactoryWorker *workers, int& count);

	std::string GetName();
	std::string GetSurname();
	int GetAge();
	std::string GetLogin();
	std::string GetPassword();
	std::string GetJobTitle();

private:

	std::string jobTitle;

};
