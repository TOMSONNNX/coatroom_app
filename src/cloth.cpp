#include <iostream>
#include <string>
#include "cloth.h"

void Cloth::clothData()
{
    std::string s;
    std::cout << "Prosze podac imie i nazwisko: ";
    getline(std::cin, s);
    getline(std::cin, owner);
    std::cout << "Prosze napisac jakie ubrania beda zostawione: ";
    getline(std::cin, clothes);
    std::cout << std::endl;
}