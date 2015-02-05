#include "classdata.h"

ClassData::ClassData()
{

}

void ClassData::addMethodData(MethodData *md) {
    this->methodVector.push_back(md);
}

