#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: aventurine <file-name>" << endl;
        return -1;
    }

    cout << "Input: " << argv[1] << endl;
}
