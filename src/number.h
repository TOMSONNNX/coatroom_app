#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>

class FileSaver;
class Coatroom;
class FileReader;

class Number
{
    static int number;

public:
    friend FileSaver;
    friend Coatroom;
    friend FileReader;
    static int createNumber();
};
#endif