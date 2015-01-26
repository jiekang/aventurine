#include "filereader.h"

#include <fstream>
#include <thread>
#include <string.h>
#include <regex>

#include "methoddata.h"

FileReader::FileReader(Storage* storage, AtomicCounter* stopSignal, char* fileName)
{
    this->storage = storage;
    this->stopSignal = stopSignal;
    this->fileName = fileName;
}

MethodData FileReader::parseLineToMethodData(std::string line) {
    int split = line.find(":");
    std::string s = line.substr(split+1);

    split = s.find(":");
    std::string enterBool = s.substr(0, split);
    bool b;
    if (enterBool == "ENTRY") {
        b = true;
    } else {
        b = false;
    }

    s = s.substr(split+1);
    split = s.find(":");
    std::string threadName = s.substr(0, split);

    s = s.substr(split+1);
    split = s.find_last_of(".");
    std::string className = s.substr(0, split);
    std::string methodName = s.substr(split+1);


    return MethodData(b, threadName, className, methodName);
}

void FileReader::parseLine(std::string line) {
    if (std::regex_match(line, std::regex(this->regex))) {
        MethodData md = parseLineToMethodData(line);
        MethodData *r = new MethodData(md.enter, md.threadName, md.className, md.methodName);
        storage->addMethodData(r);
    }
}

bool FileReader::shouldContinueReading() {
    return this->stopSignal->get() == 0;
}

void FileReader::readFile()
{
    std::string s;
    std::string line;
    int location = 0;

    while(shouldContinueReading()) {
        std::ifstream file(this->fileName);
        if (file.is_open()) {
            file.seekg(location, file.beg);
            getline(file, line);
            int seekpos = file.tellg();
            if (seekpos >= 0) {
                location = seekpos;
            }
            if (!line.empty()) {
                parseLine(line);
            }
            file.close();
        } else {
            std::cout << "Error opening file: " << fileName << std::endl;
            break;
        }
    }
    std::cout << "Done reading file. Exiting" << std::endl;
}

void FileReader::startReaderThread() {
    std::thread t(&FileReader::readFile, this);
    t.detach();
}
