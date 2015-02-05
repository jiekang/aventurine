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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QAction>
#include <QActionGroup>

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
        QGraphicsScene *methodScene;
        QGraphicsScene *classScene;
        QGraphicsView *view;

        QActionGroup *displayGroup;
        QAction *displayClass;
        QAction *displayMethod;

        QAction *autoScroll;

    private slots:
        void toggleDisplayClassData();
        void toggleDisplayMethodData();

    protected:
        void contextMenuEvent(QContextMenuEvent *event);
};

#endif // MAINWINDOW_H
