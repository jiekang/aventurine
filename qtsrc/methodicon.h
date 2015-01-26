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

        int width;
        int height;

        QRectF boundRect;
        QRectF tooltipRect;
};

#endif // METHODICON_H
