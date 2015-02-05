#ifndef CLASSDATA_H
#define CLASSDATA_H

#include <vector>

#include "methoddata.h"

class ClassData
{
    public:
        ClassData();

        void addMethodData(MethodData *md);

    private:
        std::vector<MethodData*> methodVector;
};

#endif // CLASSDATA_H
