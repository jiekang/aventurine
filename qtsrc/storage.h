#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <functional>

#include <QObject>


#include "methoddata.h"

class Storage : public QObject
{
        Q_OBJECT

    public:
        Storage();

    public slots:
        void addMethodData(MethodData* md);
    signals:
        void dataAdded(MethodData* md, int x, int y);

    private:
        int x = 0;
        int y = 0;
};

#endif // STORAGE_H
