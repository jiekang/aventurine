#include "storage.h"

#include <iostream>

Storage::Storage()
{
}

void Storage::addMethodData(MethodData* md) {
    if (md->enter) {
        this->x += 25;
    }
    emit(dataAdded(md, this->x, this->y));
    this->y += 50;

    if (!md->enter) {
        this->x -= 25;
    }
}

