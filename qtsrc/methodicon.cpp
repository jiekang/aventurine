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

#include "methodicon.h"

#include <algorithm>

#include <QtWidgets>
#include <QString>
#include <QColor>
#include <QFont>
#include <QFontMetrics>

#include "methodtooltip.h"


MethodIcon::MethodIcon(MethodData* md, int x, int y)
{
    if (md->enter) {
        this->color = QColor(0, 200, 0);
    } else {
        this->color = QColor(200, 0, 0);
    }
    this->md = md;
    this->x = x;
    this->y = y;

    this->setPos(x, y);

    this->displayTooltip = false;
    this->setZValue(0);

    calculateBoundingRect(this->md);
}

void MethodIcon::calculateBoundingRect(MethodData *md) {
    QFontMetrics fm(QFont("times", this->fontSize));

    int maxwidth = fm.width(QString("Entering"));
    maxwidth = fm.width(QString::fromUtf8(md->className.c_str())) + fm.width(QString("Class: "));
    int height = fm.height();

    maxwidth = std::max(maxwidth, fm.width(QString::fromUtf8(md->threadName.c_str())) + fm.width(QString("Thread: ")));

    maxwidth = std::max(maxwidth, fm.width(QString::fromUtf8(md->methodName.c_str())) + fm.width(QString("Method: ")));

    this->boundRect = QRectF(0, 0, maxwidth + 20, height * 5);
    this->tooltipRect = QRectF(10, 10, maxwidth + 10, height * 4);
}

QRectF MethodIcon::boundingRect() const
{
    return this->boundRect;
}

QPainterPath MethodIcon::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, this->width, this->height);
    return path;
}

void MethodIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->fillRect(QRectF(0, 0, this->width, this->height), this->color);
    painter->setFont(QFont("times", this->fontSize));
    painter->setPen(QColor(255, 255, 255));
    QString str = QString::fromUtf8(this->md->methodName.c_str());
    painter->drawText(this->width + 5, this->height/2, str);

    if (this->displayTooltip) {
        MethodTooltip m = MethodTooltip(this->md);
        m.paint(painter, item, widget, &this->tooltipRect);
    }
}

void MethodIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    this->displayTooltip = !(this->displayTooltip);
    if (this->displayTooltip) {
        this->setZValue(1);
    } else {
        this->setZValue(0);
    }

    update();
}

void MethodIcon::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    update();
}

void MethodIcon::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
