#include "methodicon.h"

#include <QtWidgets>
#include <QString>


MethodIcon::MethodIcon(const QColor &color, MethodData* md, int x, int y)
{
    this->color = color;
    this->md = md;
    this->x = x;
    this->y = y;

    this->toolTip = md->threadName + ":" + md->className + ":" + md->methodName;
    this->displayTooltip = false;

    this->setPos(x, y);
}

QRectF MethodIcon::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void MethodIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    painter->fillRect(QRectF(0, 0, 50, 50), this->color);

    if (this->displayTooltip) {
        //QFont, QFontMetrics
        QString str = QString::fromUtf8(this->toolTip.c_str());
        painter->drawText(10, 10, str);
    }

    return;
}

void MethodIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    this->displayTooltip = !(this->displayTooltip);
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
