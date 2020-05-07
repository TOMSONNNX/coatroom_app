#include <iostream>
#include "coatroom.h"
#include "cloth.h"
#include "number.h"

class Number;

void Coatroom::addToCoatroom()
{
    Cloth c;
    c.clothData();
    if (numbers.empty())
    {
        std::cout << "---------------TWOJ NUMEREK TO: " << Number::number << "------------" << std::endl;
        std::cout << std::endl;
        coatroom[Number::createNumber()] = {c.owner, c.clothes};
    }
    else
    {
        std::cout << "---------------TWOJ NUMEREK TO: " << numbers.back() << "------------" << std::endl;
        std::cout << std::endl;
        coatroom[numbers.back()] = {c.owner, c.clothes};
        numbers.pop_back();
    }
}

void Coatroom::giveClothesBack(Coatroom &c)
{
    int a;
    std::cout << "Prosze podac Pana/i numerek: ";
    std::cin >> a;
    auto search = c.coatroom.find(a);
    if (search != c.coatroom.end())
    {
        std::cout << std::endl
                  << "Oto Pana/i ubrania:  " << search->second.second << std::endl
                  << std::endl;
        c.coatroom[a] = {"-", "-"};
        numbers.push_back(a);
    }
    else
    {
        std::cout << std::endl
                  << "Nie znaleziono takiego numerka" << std::endl
                  << std::endl;
    }
}

void Coatroom::searchEmptyNumbers(Coatroom &c)
{
    for (auto it = coatroom.begin(); it != coatroom.end(); it++)
    {
        if (it->second.first == "-")
            c.numbers.push_back(it->first);
    }
}

void Coatroom::lostNumberSearch(Coatroom &c)
{
    std::string a, s;
    int i = 0;
    std::cout << "Prosze podac imie i nazwisko w celu znalezienia ubrania: " << std::endl;
    getline(std::cin, s);
    getline(std::cin, a);
    for (auto it = coatroom.begin(); it != coatroom.end(); it++)
    {
        if (it->second.first == a)
        {
            std::cout << std::endl
                      << "Oto Pana/i ubrania:  " << it->second.second << std::endl
                      << std::endl;
            c.coatroom[it->first] = {"-", "-"};
            c.numbers.push_back(it->first);
            i++;
        }
    }
    if (i == 0)
        std::cout << std::endl
                  << "Nie znaleziono ubran pod takim nazwiskiem." << std::endl
                  << std::endl;
}