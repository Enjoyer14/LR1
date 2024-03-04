#include "Models/ClassMenu/CMenu.h"
#include "Models/ClassMenuItem/CMenuItem.h"
#include "Models/ClassProduct/Product.h"
#include "Models/ClassWorker/Worker.h"
#include "Models/ClassProvider/Provider.h"
#include <fstream>

using namespace std;

const int ITEMS_NUMBER = 3;


//work
int LogIn()//\/
{
    bool isLogIn = false;
    std::string login, password;
    while (isLogIn == false) {

        std::cout << "������� �����: ";
        std::cin >> login;

        std::cout << "������� ������: ";
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
                    std::cout << "���� �������� �������. " << std::endl;
                    system("pause");
                    system("cls");
                    return 1;
                }
                else
                {
                    isLogIn = false;
                }
            }
            std::cout << "����������� ������ ����� ��� ������, ���������� �����." << std::endl;
        }
        fin.close();
    }
    return 1;
} 

#pragma region ������ � ���������

//work
void ExpandArray(FactoryWorker* workers, int& count)
{
    int newcount = count + 100;
    FactoryWorker* newworkers = new FactoryWorker[newcount];
    for (int i{}; i < count; i++)
    {
        newworkers[i] = workers[i];
    }
    delete[] workers;
    workers = newworkers;
    count = newcount;
}
void ExpandArray(Provider* workers, int& count)
{
    int newcount = count + 100;
    Provider* newworkers = new Provider[newcount];
    for (int i{}; i < count; i++)
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
            ExpandArray(workers, count);
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
            ExpandArray(providers, count);
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
    ofstream fout("Workers.txt");
    for (int i{}; i < count; i++)
    {
        fout << providers[i].GetName() << '\t' << providers[i].GetSurname() << '\t' << providers[i].GetAge() << '\t' << providers[i].GetLogin() << '\t' << providers[i].GetPassword() << '\t' << providers[i].GetProductType() << endl;
    }
    fout.close();
}

#pragma endregion


//����� 1(����� ����) work
int PrintHumanInfo(User *human ,int &currentCount, int &count)
{
    system("cls");
    for (int i{}; i < currentCount; i++)
    {
        human[i].PrintInfo();
        std::cout << std::endl;
    }
    return 1;
}

//����� 2(�������� ����) nework
int FactoryDeleteInfo(FactoryWorker *workers, int &currentCount, int &count)
{
    //Coming soon
    std::cout << "��������..." << std::endl;
    return 2;
}

//����� 3(���������� ����) //work
int FactoryAddInfo(FactoryWorker *workers, int& currentCount, int &count)
{
    system("cls");
    if (currentCount == count - 1)
    {
        ExpandArray(workers, count);
    }
    workers[currentCount].AddInfo();
    currentCount++;
    return 3;
}

#pragma region �����

//���� ������ ������ work
int Factory()
{   
    system("cls");
    int count = 100;
    FactoryWorker* workers;
    workers = new FactoryWorker[count];

    int currentCount = ReadWorkersInfoFromTxt(workers, count);

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"������� ���������� � �����������.", (CMenuItem::Function)PrintHumanInfo},
        CMenuItem{"������� ���������� � ����������.", (CMenuItem::Function)FactoryDeleteInfo},
        CMenuItem{"�������� ���������� � ����������.", (CMenuItem::Function)FactoryAddInfo}
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

#pragma endregion


#pragma region ����������

//���������� ���� (ne work)
int Provide()
{
    system("cls");
    int count = 100;
    Provider* providers;
    providers = new Provider[count];

    int currentCount = ReadProvidersInfoFromTxt(providers, count);

    CMenuItem items[ITEMS_NUMBER]{
        CMenuItem{"������� ���������� � �����������.", (CMenuItem::Function)PrintHumanInfo},
        CMenuItem{"������� ���������� � ����������.", (CMenuItem::Function)FactoryDeleteInfo},
        CMenuItem{"�������� ���������� � ����������.", (CMenuItem::Function)FactoryAddInfo}
    };
    CMenu menu("Factory Menu", items, ITEMS_NUMBER);
    while (menu.runCommand(providers, currentCount, count)) {
        system("pause");
        system("cls");
    };

    UpdateProvidersInfoInTxt(providers, currentCount);

    delete[] providers;

    return 2;
}

#pragma endregion


#pragma region ���������
//��������� ���� (ne work)
int Production()
{
    return 3;
}

#pragma endregion

int main() {
    setlocale(LC_ALL, "RU");

    LogIn();

    CMenuItem signInItems[ITEMS_NUMBER]{
         CMenuItem{"����������", Factory},
         CMenuItem{"����������", Provide},
         CMenuItem{"���������", Production}
    };
    CMenu menu("����� ������ ������", signInItems, ITEMS_NUMBER);

    while (menu.runCommand()) {
        system("pause");
        system("cls");
    };

    return 0;
}