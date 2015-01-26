#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "methoddata.h"
#include "atomiccounter.h"

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        MainWindow(AtomicCounter *c);

        ~MainWindow();

    public slots:
        void addIconToScene(MethodData *md, int x, int y);

    private:
        MainWindow(QWidget *parent = 0);

        AtomicCounter *c;
        QGraphicsScene *scene;
        QGraphicsView *view;
};

#endif // MAINWINDOW_H
