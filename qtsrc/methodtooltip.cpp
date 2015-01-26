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
        painter->drawText(15, i*20 + 25, str);
    }

}

