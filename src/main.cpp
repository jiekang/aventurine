#include <iostream>
#include <fstream>

using namespace std;

void parseLine(string line) {
    cout << "Parsing: " << line << endl;
}

void readFile(char* fileName) {
    string s;    
    string line;
    int location = 0;

    cout << "Reading file: " << fileName << endl;
    while(getline(cin, s) && s.empty()) {
        ifstream file(fileName);
        if (file.is_open()) {
            file.seekg(location, file.beg);
            getline(file, line);
            cout << location << " " << line << endl;
            int seekpos = file.tellg();
            if (seekpos >= 0) {
                location = seekpos;
            }
            if (!line.empty()) {
                parseLine(line);
            }
            file.close();
        } else {
            cout << "Unable to open file: " << fileName << endl;
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: aventurine <file-name>" << endl;
        return -1;
    }
    
    readFile(argv[1]);
}
