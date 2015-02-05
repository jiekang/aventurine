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
#include <QMenu>
#include <QContextMenuEvent>

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


    this->methodScene = new QGraphicsScene(this);
    this->methodScene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    this->classScene = new QGraphicsScene(this);
    this->classScene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    this->view = new QGraphicsView(this);
    this->view->setScene(this->methodScene);
    this->view->setMinimumSize(800, 600);
    this->view->setDragMode(QGraphicsView::ScrollHandDrag);
    this->view->show();

    this->setWindowTitle("Aventurine");

    this->displayClass = new QAction("Display classes", this);
    this->displayClass->setCheckable(true);
    connect(this->displayClass, SIGNAL(toggled(bool)), this, SLOT(toggleDisplayClassData()));

    this->displayMethod = new QAction("Display methods", this);
    this->displayMethod->setCheckable(true);
    connect(this->displayMethod, SIGNAL(toggled(bool)), this, SLOT(toggleDisplayMethodData()));

    this->displayGroup = new QActionGroup(this);
    this->displayGroup->addAction(this->displayClass);
    this->displayGroup->addAction(this->displayMethod);

    this->displayMethod->setChecked(true);

    this->autoScroll = new QAction("Autoscroll", this);
    this->autoScroll->setCheckable(true);
    this->autoScroll->setChecked(true);
}
MainWindow::~MainWindow() {
    this->c->increment();
    delete view;
    delete methodScene;
    delete classScene;

    sleep(1);
}

void MainWindow::addIconToScene(MethodData* md, int x, int y) {
    QGraphicsItem *item = new MethodIcon(md, x, y);
    this->methodScene->addItem(item);

    this->view->setSceneRect(this->methodScene->sceneRect());

    if(this->autoScroll->isChecked() && this->displayMethod->isChecked()) {
        this->view->centerOn(x, y);
    }
}

void MainWindow::toggleDisplayClassData() {
    this->view->setScene(this->classScene);
    this->view->setSceneRect(this->classScene->sceneRect());
}

void MainWindow::toggleDisplayMethodData() {
    this->view->setScene(this->methodScene);
    this->view->setSceneRect(this->methodScene->sceneRect());
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    QMenu menu(this);
    menu.addAction(this->displayClass);
    menu.addAction(this->displayMethod);
    menu.addSeparator();
    menu.addAction(this->autoScroll);
    menu.exec(event->globalPos());
}
