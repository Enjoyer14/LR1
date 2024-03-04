#include "CMenuItem.h"

CMenuItem::CMenuItem(string name, Function function) : item_name(name), functionUserIntInt(function) {}
CMenuItem::CMenuItem(string name, Func func) : item_name(name), func(func) {}


void CMenuItem::print() 
{
    std::cout << item_name;
}


int CMenuItem::run(User* worker, int &currentCount, int &count)
{
    return functionUserIntInt(worker, currentCount, count);
}

int CMenuItem::run()
{
    return func();
}

