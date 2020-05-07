#ifndef COATROOM_H
#define COATROOM_H
#include <iostream>
#include <map>
#include <vector>
#include "filesaver.h"

class FileReader;
class FileSaver;

class Coatroom
{
    std::map<int, std::pair<std::string, std::string>> coatroom;
    std::vector<int> numbers;

public:
    friend FileReader;
    friend FileSaver;
    void addToCoatroom();
    void giveClothesBack(Coatroom &);
    void searchEmptyNumbers(Coatroom &);
    void lostNumberSearch(Coatroom &);
};
#endif