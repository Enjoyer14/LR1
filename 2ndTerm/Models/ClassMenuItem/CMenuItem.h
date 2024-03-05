#pragma once

#include <iostream>
#include <string>
#include "C:\Users\stass\OneDrive\Рабочий стол\2ndTerm\Models\ClassUser\User.h"
#include "C:\Users\stass\OneDrive\Рабочий стол\2ndTerm\Models/ClassWorker/Worker.h"
#include "C:\Users\stass\OneDrive\Рабочий стол\2ndTerm\Models/ClassProvider/Provider.h"

using namespace std;

class CMenuItem {
public:

    typedef int(*Func)();
    typedef int(*Function)(User*, int&, int&);


    CMenuItem(string, Function);
    CMenuItem(string, Func);

    Function functionUserIntInt{};
    Func func{};

    string item_name{};
    void print();

    int run(User* worker, int& currentCount, int& count);
    int run();
};

