#pragma once

#include <cstddef>
#include <string>
#include "/home/sso23ki223/Table/2ndTerm/Models/ClassMenuItem/CMenuItem.h"

using namespace std;

class CMenu {
public:
    CMenu(string, CMenuItem*, size_t);
    void print();
    int runCommand(User* worker, int &currentCount, int &count);
    int runCommand();

private:
    int select{ -1 };
    size_t count{};
    string title{};
    CMenuItem* items{};
};