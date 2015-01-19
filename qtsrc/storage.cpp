#include "storage.h"

#include <iostream>

Storage::Storage()
{

}

void Storage::addWorkerFunction(std::function<void(MethodData*)> workerFunction) {
    this->func_list.push_back(workerFunction);
}

void Storage::addMethodData(MethodData* methodData) {
    for(auto & element : this->func_list) {
        element(methodData);
    }
}

