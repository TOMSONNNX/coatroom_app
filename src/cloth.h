#ifndef CLOTH_H
#define CLOTH_H

#include <iostream>
#include "coatroom.h"
#include "filereader.h"

class Coatroom;
class FileReader;

class Cloth
{
    friend Coatroom;
    friend FileReader;
    std::string clothes;
    std::string owner;
    void clothData();
};
#endif