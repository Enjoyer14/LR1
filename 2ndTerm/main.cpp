#include "Models/ClassMenu/CMenu.h"
#include "Models/ClassMenuItem/CMenuItem.h"
#include "Models/ClassProduct/Product.h"
#include "Models/ClassWorker/Worker.h"
#include "Models/ClassProvider/Provider.h"
#include <fstream>

using namespace std;

const int ITEMS_NUMBER = 3;


// ./main.cpp ./Models/ClassMenuItem/CMenuItem.cpp ./Models/ClassMenu/CMenu.cpp ./Models/ClassUser/User.cpp ./Models/ClassWorker/Worker.cpp ./Models/ClassProvider/Provider.cpp ./Models/ClassProduct/Product.cpp

//work
int LogIn()
{
    bool isLogIn = false;
    std::string login, password;
    while (isLogIn == false) {

        std::cout << "Enter login: ";
        std::cin >> login;

        std::cout << "Enter password: ";
        std::cin >> password;

        ifstream fin("Logs.txt");
        std::string buffLogin, buffPassword;
        if (fin.is_open()) 
        {
            while (fin >> buffLogin >> buffPassword) 
            {
                if (login == buffLogin && password == buffPassword) 
                {
                    isLogIn = true;
                    fin.close();
                    std::cout << "Succesfully. " << std::endl;

                    return 1;
                }
                else
                {
                    isLogIn = false;
                }
            }
            std::cout << "Wrong login or password, try again." << std::endl;
        }
        fin.close();
    }
    return 1;
} 

#pragma region 

//work
void ExpandArray(FactoryWorker *workers, int& currentCount, int& count)
{
    int newcount = count + 100;
    FactoryWorker* newworkers = new FactoryWorker[newcount];
    for (int i{}; i < currentCount; i++)
    {
        newworkers[i] = workers[i];
    }
    delete[] workers;
    workers = newworkers;
    count = newcount;
}
void ExpandArray(Provider *workers, int& currentCount, int& count)
{
    int newcount = count + 100;
    Provider* newworkers = new Provider[newcount];
    for (int i{}; i < currentCount; i++)
    {
        newworkers[i] = workers[i];
    }
    delete[] workers;
    workers = newworkers;
    count = newcount;
}

//work
int ReadWorkersInfoFromTxt(FactoryWorker *workers, int &count)
{
    int i{};
    ifstream fin("Workers.txt");
    while (fin >> workers[i].name >> workers[i].surname >> workers[i].age >> workers[i].login >> workers[i].password >> workers[i].jobTitle) {
        i++;
        if (i == count-1)
        {
            ExpandArray(workers, i, count);
        }
    }
    fin.close();
    return i;
}

//work
int ReadProvidersInfoFromTxt(Provider *providers, int& count)
{
    int i{};
    ifstream fin("Providers.txt");
    while (fin >> providers[i].name >> providers[i].surname >> providers[i].age >> providers[i].login >> providers[i].password >> providers[i].productType) {
        i++;
        if (i == count - 1)
        {
            ExpandArray(providers, i, count);
        }
    }
    fin.close();
    return i;
}

//work
void UpdateWorkersInfoInTxt(FactoryWorker *workers, int count)
{
    ofstream fout("Workers.txt");
    for (int i{}; i < count; i++)
    {
        fout << workers[i].GetName() << '\t' << workers[i].GetSurname() << '\t' << workers[i].GetAge() << '\t' << workers[i].GetLogin() << '\t' << workers[i].GetPassword() << '\t' << workers[i].GetJobTitle() << endl;
    }
    fout.close();
}

//work
void UpdateProvidersInfoInTxt(Provider *providers, int count)
{
    ofstream fout("Providers.txt");
    for (int i{}; i < count; i++)
    {
        fout << providers[i].GetName() << '\t' << providers[i].GetSurname() << '\t' << providers[i].GetAge() << '\t' << providers[i].GetLogin() << '\t' << providers[i].GetPassword() << '\t' << providers[i].GetProductType() << endl;
    }
    fout.close();
}

#pragma endregion


int PrintFactoryInfo(FactoryWorker *human ,int &currentCount, int &count)
{

    for (int i{}; i < currentCount; i++)
    {
        std::cout << i + 1 << "-th" << std::endl;
        human[i].PrintInfo();
        std::cout << std::endl;
    }
    return 1;
}
int PrintProviderInfo(Provider* human, int& currentCount, int& count)
{

    for (int i{}; i < currentCount; i++)
    {
        std::cout << i + 1 << "-th" << std::endl;
        human[i].PrintInfo();
        std::cout << std::endl;
    }
    return 1;
}

int FactoryChangeInfo(FactoryWorker *human, int &currentCount, int &count)
{
    PrintFactoryInfo(human, currentCount, count);

    std::cout << "Choose variant: ";
    int variant{};
    std::cin >> variant;
    std::cin.ignore(32767, '\n');
    variant--;

    FactoryWorker buff;
    buff.AddInfo();

    human[variant] = buff;

    return 2;
}
int ProviderChangeInfo(Provider* human, int& currentCount, int& count)
{
    PrintProviderInfo(human, currentCount, count);

    std::cout << "Choose variant: ";
    int variant{};
    std::cin >> variant;
    std::cin.ignore(32767, '\n');
    variant--;

    Provider buff;
    buff.AddInfo();

    human[variant] = buff;

    return 2;
}


int HumanAddInfo(FactoryWorker *humans, int &currentCount, int &count)
{
    if (currentCount == count - 1)
    {
        ExpandArray(humans, currentCount, count);
    }
    humans[currentCount].AddInfo();
    currentCount++;
    return 3;
}

//���� ������ ������ work
int Factory()
{   

    int count = 100;
    FactoryWorker* workers;
    workers = new FactoryWorker[count];

    int currentCount = ReadWorkersInfoFromTxt(workers, count);

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Print worker info", (CMenuItem::Function)PrintFactoryInfo},
        CMenuItem{"Change worker info.", (CMenuItem::Function)FactoryChangeInfo},
        CMenuItem{"Add human info.", (CMenuItem::Function)HumanAddInfo}
    };
    CMenu menu("Factory Menu", items, ITEMS_NUMBER);
    while (menu.runCommand(workers, currentCount, count)) {
;
    };

    UpdateWorkersInfoInTxt(workers, currentCount);

    delete[] workers;

    return 1;
}

//���������� ���� (ne work)
int Provide()
{

    int count = 100;
    Provider* providers;
    providers = new Provider[count];

    int currentCount = ReadProvidersInfoFromTxt(providers, count);

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Print provider info", (CMenuItem::Function)PrintProviderInfo},
        CMenuItem{"Change provider info.", (CMenuItem::Function)FactoryChangeInfo},
        CMenuItem{"Add provider info.", (CMenuItem::Function)HumanAddInfo}
    };
    CMenu menu("Provider Menu", items, ITEMS_NUMBER);
    while (menu.runCommand(providers, currentCount, count)) {;
    };

    UpdateProvidersInfoInTxt(providers, currentCount);

    delete[] providers;

    return 2;
}

// g++ ./main.cpp ./Models/ClassMenuItem/CMenuItem.cpp ./Models/ClassMenu/CMenu.cpp ./Models/ClassUser/User.cpp ./Models/ClassWorker/Worker.cpp ./Models/ClassProvider/Provider.cpp ./Models/ClassProduct/Product.cpp

//��������� ���� (ne work)
int Production()
{
    Product product;
    product.AddInfo();
    product.Print();
    return 3;
}


int main() {

    setlocale(LC_ALL, "RU");

    LogIn();

    CMenuItem items[ITEMS_NUMBER]{
         CMenuItem{"Factory", Factory},
         CMenuItem{"Provider", Provide},
         CMenuItem{"Production", Production}
    };
    CMenu menu("Choosing", items, ITEMS_NUMBER);

    while (menu.runCommand()) {

    };

    return 0;
}