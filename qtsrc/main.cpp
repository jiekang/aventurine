#include <iostream>

#include <QApplication>
#include <QObject>

#include "mainwindow.h"
#include "atomiccounter.h"
#include "filereader.h"

#include "methoddata.h"
#include "storage.h"

#include "controllertemp.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: aventurine <file-name>" << std::endl;
        return -1;
    }

    QApplication a(argc, argv);

    AtomicCounter c;

    Storage s;

    MainWindow w(&c);
    ControllerTemp t;
    t.connect(&w, &s);


    FileReader f(&s, &c, argv[1]);
    f.startReaderThread();

    w.show();

    return a.exec();
}
