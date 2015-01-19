#include <iostream>

#include <QApplication>

#include "mainwindow.h"
#include "atomiccounter.h"
#include "filereader.h"

#include "methoddata.h"
#include "storage.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: aventurine <file-name>" << std::endl;
        return -1;
    }

    Storage s;
    AtomicCounter c;

    FileReader f(&s, &c, argv[1]);

    f.startReaderThread();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
