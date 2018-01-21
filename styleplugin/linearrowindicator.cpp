#include "linearrowindicator.h"

LineArrowIndicator::LineArrowIndicator(QQuickItem *parent) : QQuickPaintedItem(parent),
    m_arrowColor(Qt::black)
{
    connect(this, SIGNAL(colorChanged()), this, SLOT(update()));
}

void LineArrowIndicator::paint(QPainter *painter)
{
    QQuickPaintedItem::setAntialiasing(true);
    if(opacity() > 0)
    {
        QPainterPath arrowPath;
        arrowPath.moveTo(1, 1);
        arrowPath.lineTo(width() * .5, height() - 1);
        arrowPath.lineTo(width() - 1, 1);

        QPen arrowPen(QBrush(m_arrowColor), 2);
        arrowPen.setCapStyle(Qt::RoundCap);
        painter->setPen(arrowPen);

        painter->drawPath(arrowPath);
    }
}
