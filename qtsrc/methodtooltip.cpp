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

#include "methodtooltip.h"

MethodTooltip::MethodTooltip(MethodData *md)
{
    if (md->enter) {
        this->tooltip[0] = "Entering";
    } else {
        this->tooltip[0] = "Exiting";
    }
    this->tooltip[1] = "Thread: " + md->threadName;
    this->tooltip[2] = "Class: " + md->className;
    this->tooltip[3] = "Method: " + md->methodName;
}

void MethodTooltip::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget, QRectF* tooltipRect) {
    painter->fillRect(*tooltipRect, QColor(255, 255, 255));


    for (int i = 0; i < 4; i++) {
        QString str = QString::fromUtf8(this->tooltip[i].c_str());
        painter->setPen(QColor(0, 0, 0));
        painter->drawText(15, i*13 + 25, str);
    }

}

