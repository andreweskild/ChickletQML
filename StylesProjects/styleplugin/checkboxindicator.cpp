#include "checkboxindicator.h"

CheckBoxIndicator::CheckBoxIndicator(QQuickItem *parent) : QQuickPaintedItem(parent),
    m_checkColor(Qt::black),
    m_checkWidth(0),
    m_dashOffset(6)
{
    connect(this, SIGNAL(widthChanged()), this, SLOT(update()));
    connect(this, SIGNAL(heightChanged()), this, SLOT(update()));
    connect(this, SIGNAL(colorChanged()), this, SLOT(update()));
}

void CheckBoxIndicator::paint(QPainter *painter)
{
    QQuickPaintedItem::setAntialiasing(true);
    if (opacity() > 0)
    {
        QPainterPath checkPath;
        checkPath.moveTo(width()*.25, height() * .5);
        checkPath.lineTo(width() * .45, height() * .66);
        checkPath.lineTo(width()*.75, height() * .35);

        QPen checkPen(QBrush(m_checkColor), m_checkWidth);
        checkPen.setCapStyle(Qt::RoundCap);
        QVector<qreal> dashes;
        dashes << 12 << 12;
        checkPen.setDashOffset(m_dashOffset);
        checkPen.setDashPattern(dashes);
        painter->setPen(checkPen);

        painter->drawPath(checkPath);
    }
}

qreal CheckBoxIndicator::dashOffset() const
{
    return m_dashOffset;
}

void CheckBoxIndicator::setDashOffset(qreal &p_dashOffset)
{
    if(m_dashOffset != p_dashOffset)
    {
        m_dashOffset = p_dashOffset;
        update();
        emit dashOffsetChanged();
    }
}
