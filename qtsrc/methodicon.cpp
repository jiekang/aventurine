#include "methodicon.h"

MethodIcon::MethodIcon(const QColor &color, MethodData* md, int x, int y)
{
    this->color = color;
    this->md = md;
    this->x = x;
    this->y = y;
}

QRectF MethodIcon::boundingRect() const
{
    return QRectF(0, 0, 110, 10);
}

QPainterPath MethodIcon::shape() const
{
    QPainterPath path;
    path.addRect(10, 10, 10, 10);
    return path;
}

void MethodIcon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

void MethodIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
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
