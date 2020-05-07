#include <iostream>
#include <fstream>
#include "filesaver.h"
#include "coatroom.h"

class Coatroom;

void FileSaver::saveFile(Coatroom c)
{
    std::fstream file;
    file.open("szatnia.txt", std::ios::out);
    for (auto it = c.coatroom.begin(); it != c.coatroom.end(); it++)
        file << it->first << std::endl
             << it->second.first << std::endl
             << it->second.second << std::endl;
    file.close();
}
