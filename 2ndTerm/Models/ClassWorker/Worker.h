#pragma once
#include <string>
#include <iostream>
#include "/home/sso23ki223/Table/2ndTerm/Models/ClassUser/User.h"


class FactoryWorker : public User
{
public:

	FactoryWorker();
	FactoryWorker(std::string name, std::string surname, int age, std::string login, std::string password, std::string jobTitle);
	
	void PrintInfo () override;
	void AddInfo() override;

	void operator = (FactoryWorker other);

	friend int ReadWorkersInfoFromTxt(FactoryWorker *workers, int& count);

	std::string GetJobTitle();

private:

	std::string jobTitle;

};
