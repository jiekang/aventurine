#ifndef METHODICON_H
#define METHODICON_H

#include <iostream>

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
        std::string toolTip;
        bool displayTooltip;
};

#endif // METHODICON_H
