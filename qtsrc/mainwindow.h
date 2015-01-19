#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "methoddata.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        void addToScene(MethodData *md, int x, int y);
    private:
        void createScene();

        QGraphicsScene *scene;
        QGraphicsView *view;
};

#endif // MAINWINDOW_H
