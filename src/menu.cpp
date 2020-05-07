#include <iostream>
#include "menu.h"
#include "coatroom.h"
#include "filereader.h"
#include "filesaver.h"

class FileSaver;
class Coatroom;
class FileReader;

void Menu::menu()
{
    Coatroom coatroom_;
    FileReader::readFile(coatroom_);
    coatroom_.searchEmptyNumbers(coatroom_);

    for (;;)
    {
        int a;
        std::cout << "1. Zostaw ubrania" << std::endl;
        std::cout << "2. Odbierz ubrania" << std::endl;
        std::cout << "3. Zgubilem numerek" << std::endl;
        std::cout << "4. Wyjscie" << std::endl;
        std::cout << "Twoj wybor: ";
        std::cin >> a;
        switch (a)
        {
        case 1:
            coatroom_.addToCoatroom();
            FileSaver::saveFile(coatroom_);
            break;
        case 2:
            coatroom_.giveClothesBack(coatroom_);
            FileSaver::saveFile(coatroom_);
            break;
        case 3:
            coatroom_.lostNumberSearch(coatroom_);
            FileSaver::saveFile(coatroom_);
            break;
        case 4:
            FileSaver::saveFile(coatroom_);
            return;
        }
    }
}