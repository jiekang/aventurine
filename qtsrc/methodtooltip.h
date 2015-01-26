#ifndef METHODTOOLTIP_H
#define METHODTOOLTIP_H

#include <iostream>

#include <QPainter>
#include <QGraphicsItem>

#include "methoddata.h"

class MethodTooltip
{
    public:
        MethodTooltip(MethodData *md);
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget, QRectF *tooltipRect);

    private:
        std::string tooltip[4];
        int length = 0;
        int width = 0;
};

#endif // METHODTOOLTIP_H
