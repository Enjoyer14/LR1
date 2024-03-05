#include "CMenu.h"

CMenu::CMenu(string title, CMenuItem *items, size_t count) : title(title), items(items), count(count) {}

void CMenu::print() {
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ".";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << "0.Выход" << std::endl;
}

int CMenu::runCommand(User* worker, int &currentCount, int &count) {
    print();
    std::cout << "\nВыбор: ";
    std::cin >> select;
    std::cin.ignore(32767, '\n');
    if(select <= 0){
        return 0;
    }
    return items[select - 1].run(worker, currentCount, count);
}

int CMenu::runCommand() {
    print();
    std::cout << "\nВыбор: ";
    std::cin >> select;
    if (select <= 0) {
        return 0;
    }
    return items[select - 1].run();
}