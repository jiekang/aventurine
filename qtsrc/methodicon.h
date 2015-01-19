#ifndef METHODICON_H
#define METHODICON_H

#include <QColor>
#include <QGraphicsItem>

#include "methoddata.h"

class MethodIcon : public QGraphicsItem
{
    public:
        MethodIcon(const QColor &color,
                   MethodData* md,
                   int x, int y);

        QRectF boundingRect() const Q_DECL_OVERRIDE;
        QPainterPath shape() const Q_DECL_OVERRIDE;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

    private:
        QColor color;
        MethodData* md;
        int x;
        int y;
};

#endif // METHODICON_H
