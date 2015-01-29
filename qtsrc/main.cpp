/*
    Aventurine Alpha
    Copyright (C) 2014  Jie Kang

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

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
