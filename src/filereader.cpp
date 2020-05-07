#include <iostream>
#include <fstream>
#include "filereader.h"
#include "cloth.h"
#include "coatroom.h"
#include "number.h"

class Cloth;
class Coatroom;
class Number;

void FileReader::readFile(Coatroom &c)
{
    std::fstream file;
    file.open("szatnia.txt", std::ios::in);
    if (file.is_open() == false)
    {
        std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
        return;
    }
    std::string line;
    int line_number = 1;
    Cloth x;
    while (getline(file, line))
    {
        switch (line_number)
        {
        case 1:
            Number::number = stoi(line);
            break;
        case 2:
            x.owner = line;
            break;
        case 3:
            x.clothes = line;
            c.coatroom[Number::number] = {x.owner, x.clothes};
            line_number = 0;
            break;
        default:
            break;
        }
        line_number++;
    }
    file.close();
    Number::number++;
}