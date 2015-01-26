#include "storage.h"

#include <iostream>

Storage::Storage()
{
}

void Storage::addMethodData(MethodData* md) {

    emit(dataAdded(md, this->x, this->y));
    this->y += 75;
    this->x += 15;
}

