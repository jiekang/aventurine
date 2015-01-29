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

#ifndef METHODICON_H
#define METHODICON_H

#include <iostream>

#include <QGraphicsItem>

#include "methoddata.h"
#include "methodtooltip.h"

class MethodIcon : public QGraphicsItem
{
    public:
        MethodIcon(MethodData* md, int x, int y);

        QRectF boundingRect() const Q_DECL_OVERRIDE;
        QPainterPath shape() const Q_DECL_OVERRIDE;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

    private:
        void calculateBoundingRect(MethodData *md);

        QColor color;
        MethodData* md;
        MethodTooltip* mt;
        int x;
        int y;
        bool displayTooltip;

        const int width = 30;
        const int height = 30;

        const int fontSize = 8;



        QRectF boundRect;
        QRectF tooltipRect;
};

#endif // METHODICON_H
