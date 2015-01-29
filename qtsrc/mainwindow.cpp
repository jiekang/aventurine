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
#include <unistd.h>

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

    sleep(1);
}

void MainWindow::addIconToScene(MethodData* md, int x, int y) {
    QGraphicsItem *item = new MethodIcon(md, x, y);
    this->scene->addItem(item);
    this->view->setSceneRect(this->scene->sceneRect());
    this->view->centerOn(x, y);
}
