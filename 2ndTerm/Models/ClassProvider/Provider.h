#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include "C:\Users\stass\OneDrive\������� ����\2ndTerm\Models\ClassUser\User.h"

class Provider : public User {

public:
	Provider();
	Provider(std::string name, std::string surname, int age, std::string login, std::string password, std::string productType);

	void PrintInfo() override;
	void AddInfo() override;	

	void operator = (Provider other);
	
	friend std::istream& operator>> (std::istream& in, std::vector<Provider>& human);

	static int PrintFullInfo(std::vector<Provider> &human);
	static int ProviderAddInfo(std::vector<Provider>& human);
	static int DeleteProviderInfo(std::vector<Provider>& human);

	std::string GetProductType();

	void Clear();

	static void ReadProvidersInfoFromTxt(std::vector<Provider>& human);
	static void UpdateProvidersInfoInTxt(std::vector<Provider>& human);

private:

	std::string productType;
};

