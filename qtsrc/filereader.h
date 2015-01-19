#ifndef FILEREADER_H
#define FILEREADER_H

#include<iostream>

#include "storage.h"
#include "atomiccounter.h"

class FileReader
{
    public:
        FileReader(Storage* storage, AtomicCounter* stopSignal, char* fileName);
        void startReaderThread();

    private:
        const std::string regex = "BM:((ENTRY)|(EXIT)):.*:.*";

        MethodData parseLineToMethodData(std::string line);
        void parseLine(std::string line);
        bool shouldContinueReading();
        void readFile();

        Storage* storage;
        AtomicCounter* stopSignal;
        char* fileName;
};

#endif // FILEREADER_H
