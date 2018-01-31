#include "dialarcindicator.h"

DialArcIndicator::DialArcIndicator(QQuickItem *p_parent) : QQuickPaintedItem(p_parent),
    m_progress(0)
{
    connect(this, SIGNAL(progressChanged()), this, SLOT(updateArc()));
    updateArc();
}

void DialArcIndicator::updateArc()
{
    if (!m_path.isEmpty())
    {
        m_path = QPainterPath();
    }
    qreal borderAdjustment = m_arcWidth * .5;
    QRectF rect(boundingRect().adjusted(borderAdjustment, borderAdjustment, -borderAdjustment, -borderAdjustment));
    m_path.arcTo(rect, -135, (-270.0 * m_progress));
    m_endPoint = m_path.currentPosition();
    emit endPointChanged();
    update();
}

void DialArcIndicator::paint(QPainter *p_painter)
{
    QQuickPaintedItem::setAntialiasing(true);

    QPen checkPen(QBrush(m_arcColor), m_arcWidth);
    checkPen.setCapStyle(Qt::RoundCap);
    p_painter->setPen(checkPen);
//    QRectF rect(boundingRect().adjusted(borderAdjustment, borderAdjustment, -borderAdjustment, -borderAdjustment));
//    QPainterPath path;
//    path.arcTo(rect, -135, (-270.0 * m_progress));
    p_painter->drawPath(m_path);
}
