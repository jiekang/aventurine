#include <iostream>
#include <fstream>
#include <atomic>
#include <thread>

using namespace std;

struct AtomicCounter {
    atomic<int> value {0};

    void increment() {
        ++value;
    }

    int get() {
        return value.load();
    }
};

void waitForExit(AtomicCounter* counter) {
    string s;
    while(getline(cin, s) && s.empty()) {
    }
    counter->increment();
}

void parseLine(int location, string line) {
    cout << "Parsing: " << location << " : " << line << endl;
}

void readFile(AtomicCounter* counter, char* fileName) {
    string s;    
    string line;
    int location = 0;

    cout << "Reading file: " << fileName << endl;
    while(counter->get() == 0) {
        ifstream file(fileName);
        if (file.is_open()) {
            file.seekg(location, file.beg);
            getline(file, line);
            int seekpos = file.tellg();
            if (seekpos >= 0) {
                location = seekpos;
            }
            if (!line.empty()) {
                parseLine(location, line);
            }
            file.close();
        } else {
            cout << "Unable to open file: " << fileName << endl;
            break;
        }
    }
    cout << "Done reading file. Exiting" << endl;
}

void startReaderThread(AtomicCounter* counter, char* fileName) {
    thread t(readFile, counter, fileName);
    t.detach();
}

int main(int argc, char* argv[]) {
    struct AtomicCounter c;
    if (argc != 2) {
        cout << "Usage: aventurine <file-name>" << endl;
        return -1;
    }
    startReaderThread(&c, argv[1]);
    waitForExit(&c);
}
