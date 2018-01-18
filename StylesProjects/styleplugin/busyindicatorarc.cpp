#include "busyindicatorarc.h"

BusyIndicatorArc::BusyIndicatorArc(QQuickItem *p_parent) : QQuickPaintedItem(p_parent),
    m_arcLength(120)
{
    connect(this, SIGNAL(arcLengthChanged()), this, SLOT(update()));
}

void BusyIndicatorArc::paint(QPainter *p_painter)
{
    QQuickPaintedItem::setAntialiasing(true);

    QPen checkPen(QBrush(m_arcColor), m_arcWidth);
    checkPen.setCapStyle(Qt::RoundCap);
    p_painter->setPen(checkPen);
    qreal borderAdjustment = m_arcWidth * .5;
    QRectF rect(boundingRect().adjusted(borderAdjustment, borderAdjustment, -borderAdjustment, -borderAdjustment));
    p_painter->drawArc(rect, 30 * 16, m_arcLength * 16);
}
