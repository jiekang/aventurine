#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <functional>

#include "methoddata.h"

class Storage
{
    public:
        Storage();

        void addWorkerFunction(std::function<void (MethodData*)> workerFunction);
        void addMethodData(MethodData* methodData);

    private:
        std::vector<std::function<void (MethodData*)>> func_list;
};

#endif // STORAGE_H
