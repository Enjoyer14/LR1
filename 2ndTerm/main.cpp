#include "Models/ClassMenu/CMenu.h"
#include "Models/ClassMenuItem/CMenuItem.h"
#include "Models/ClassProduct/Product.h"
#include "Models/ClassWorker/Worker.h"
#include "Models/ClassProvider/Provider.h"
#include <fstream>

using namespace std;

const int ITEMS_NUMBER = 3;


//work
int LogIn()
{
    bool isLogIn = false;
    std::string login, password;
    while (isLogIn == false) {

        std::cout << "Введите логин: ";
        std::cin >> login;

        std::cout << "Введите пароль: ";
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
                    std::cout << "Вход выполнен успешно. " << std::endl;
                    system("pause");
                    system("cls");
                    return 1;
                }
                else
                {
                    isLogIn = false;
                }
            }
            std::cout << "Неправильно введен логин или пароль, попробуйте снова." << std::endl;
        }
        fin.close();
    }
    return 1;
} 

#pragma region Работа с массивами

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
    system("cls");
    for (int i{}; i < currentCount; i++)
    {
        std::cout << i + 1 << "-ый(ой)" << std::endl;
        human[i].PrintInfo();
        std::cout << std::endl;
    }
    return 1;
}
int PrintProviderInfo(Provider* human, int& currentCount, int& count)
{
    system("cls");
    for (int i{}; i < currentCount; i++)
    {
        std::cout << i + 1 << "-ый(ой)" << std::endl;
        human[i].PrintInfo();
        std::cout << std::endl;
    }
    return 1;
}

int FactoryChangeInfo(FactoryWorker *human, int &currentCount, int &count)
{
    PrintFactoryInfo(human, currentCount, count);

    std::cout << "Выберите изменяемого: ";
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

    std::cout << "Выберите изменяемого: ";
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
    system("cls");
    if (currentCount == count - 1)
    {
        ExpandArray(humans, currentCount, count);
    }
    humans[currentCount].AddInfo();
    currentCount++;
    return 3;
}

//меню завода вполне work
int Factory()
{   
    system("cls");
    int count = 100;
    FactoryWorker* workers;
    workers = new FactoryWorker[count];

    int currentCount = ReadWorkersInfoFromTxt(workers, count);

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Вывести информацию о сотрудниках.", (CMenuItem::Function)PrintFactoryInfo},
        CMenuItem{"Изменить информацию о сотруднике.", (CMenuItem::Function)FactoryChangeInfo},
        CMenuItem{"Добавить информацию о сотруднике.", (CMenuItem::Function)HumanAddInfo}
    };
    CMenu menu("Factory Menu", items, ITEMS_NUMBER);
    while (menu.runCommand(workers, currentCount, count)) {
        system("pause");
        system("cls");
    };

    UpdateWorkersInfoInTxt(workers, currentCount);

    delete[] workers;

    return 1;
}

//Поставщики меню (ne work)
int Provide()
{
    system("cls");
    int count = 100;
    Provider* providers;
    providers = new Provider[count];

    int currentCount = ReadProvidersInfoFromTxt(providers, count);

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"Вывести информацию о поставщиках.", (CMenuItem::Function)PrintProviderInfo},
        CMenuItem{"Изменить информацию о поставщике.", (CMenuItem::Function)FactoryChangeInfo},
        CMenuItem{"Добавить информацию о поставщике.", (CMenuItem::Function)HumanAddInfo}
    };
    CMenu menu("Provider Menu", items, ITEMS_NUMBER);
    while (menu.runCommand(providers, currentCount, count)) {
        system("pause");
        system("cls");
    };

    UpdateProvidersInfoInTxt(providers, currentCount);

    delete[] providers;

    return 2;
}


//Продукция меню (ne work)
int Production()
{
    
    return 3;
}


int main() {

    setlocale(LC_ALL, "RU");

    LogIn();

    CMenuItem items[ITEMS_NUMBER]{
         CMenuItem{"Сотрудники", Factory},
         CMenuItem{"Поставщики", Provide},
         CMenuItem{"Продукция", Production}
    };
    CMenu menu("Выбор режима работы", items, ITEMS_NUMBER);

    while (menu.runCommand()) {
        system("pause");
        system("cls");
    };

    return 0;
}