#include <iostream>

#include <QColor>
#include <QGraphicsItem>
#include <QHBoxLayout>

#include "mainwindow.h"
#include "methodicon.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->view = new QGraphicsView(this);

    this->scene = new QGraphicsScene(this);

    this->view->setScene(scene);

    this->setWindowTitle("Aventurine");
    this->addToScene(new MethodData(false, "a", "b", "c"), 0, 0);
    this->addToScene(new MethodData(false, "a", "b", "c"), 0, 100);
    this->addToScene(new MethodData(false, "a", "b", "c"), 100, 100);
    this->addToScene(new MethodData(false, "a", "b", "c"), 100, 0);
}

void MainWindow::addToScene(MethodData* md, int x, int y) {
    QColor color(0, 255, 0);
    QGraphicsItem *item = new MethodIcon(color, md, x, y);
    this->scene->addItem(item);

    QRectF rect = this->scene->itemsBoundingRect();
    this->view->setMinimumSize(rect.width(), rect.height());
}
