#include <iostream>

#include <QColor>
#include <QGraphicsItem>
#include <QHBoxLayout>

#include "mainwindow.h"
#include "methodicon.h"

MainWindow::MainWindow(AtomicCounter *c)
    : MainWindow()
{
    this->c = c;
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    this->view = new QGraphicsView(this);

    this->scene = new QGraphicsScene(this);

    this->view->setScene(scene);
    this->view->setMinimumSize(800, 600);
    this->view->setDragMode(QGraphicsView::ScrollHandDrag);
    this->view->show();

    this->setWindowTitle("Aventurine");

    this->scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
}
MainWindow::~MainWindow() {
    this->c->increment();
    delete view;
    delete scene;
}

void MainWindow::addIconToScene(MethodData* md, int x, int y) {
    QGraphicsItem *item = new MethodIcon(md, x, y);
    this->scene->addItem(item);
    this->view->setSceneRect(this->scene->sceneRect());
}
