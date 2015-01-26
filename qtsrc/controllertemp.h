#ifndef CONTROLLERTEMP_H
#define CONTROLLERTEMP_H

#include <QObject>

#include "mainwindow.h"
#include "storage.h"

class ControllerTemp : public QObject
{
        Q_OBJECT

    public:
        ControllerTemp();

        void connect(MainWindow* w, Storage* s);
};

#endif // CONTROLLERTEMP_H
