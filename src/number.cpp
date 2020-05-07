#include <iostream>
#include "number.h"
#include "filesaver.h"
#include "filereader.h"

int Number::createNumber()
{
    return number++;
}
int Number::number = 1;