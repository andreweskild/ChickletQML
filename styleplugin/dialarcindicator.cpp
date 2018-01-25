#include "dialarcindicator.h"

DialArcIndicator::DialArcIndicator(QQuickItem *p_parent) : QQuickPaintedItem(p_parent),
    m_progress(0)
{
    connect(this, SIGNAL(progressChanged()), this, SLOT(update()));
}


void DialArcIndicator::paint(QPainter *p_painter)
{
    QQuickPaintedItem::setAntialiasing(true);

    QPen checkPen(QBrush(m_arcColor), m_arcWidth);
    checkPen.setCapStyle(Qt::RoundCap);
    p_painter->setPen(checkPen);
    qreal borderAdjustment = m_arcWidth * .5;
    QRectF rect(boundingRect().adjusted(borderAdjustment, borderAdjustment, -borderAdjustment, -borderAdjustment));
    p_painter->drawArc(rect, -135 * 16, (-270.0 * m_progress * 16.0));
}
