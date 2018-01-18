#include "delaybuttonprogressindicator.h"

DelayButtonProgressIndicator::DelayButtonProgressIndicator(QQuickItem *p_parent) : QNanoQuickItem(p_parent)
{
    connect(this, SIGNAL(colorChanged()), this, SLOT(update()));
    connect(this, SIGNAL(progressChanged()), this, SLOT(update()));
}

QColor DelayButtonProgressIndicator::color() const
{
    return m_color;
}

void DelayButtonProgressIndicator::setColor(const QColor &p_color)
{
    if(p_color != m_color)
    {
        m_color = p_color;
        emit colorChanged();
    }
}

qreal DelayButtonProgressIndicator::progressWidth() const
{
    return width() * m_progress;
}

QNanoQuickItemPainter *DelayButtonProgressIndicator::createItemPainter() const
{
    return new DelayButtonProgressPainter();
}

DelayButtonProgressPainter::DelayButtonProgressPainter()
{
}


void DelayButtonProgressPainter::paint(QNanoPainter *p)
{
    p->beginPath();
    p->roundedRect(0, 0,
                   width(), height(), M_RADIUS);
    p->setClipRect(0, 0, m_progress, height());
    p->setFillStyle(m_color);
    p->fill();
}

void DelayButtonProgressPainter::synchronize(QNanoQuickItem *p_item)
{
    DelayButtonProgressIndicator *item = static_cast<DelayButtonProgressIndicator *>(p_item);
    if(item)
    {
        m_color = QNanoColor::fromQColor(item->color());
        m_progress = item->progressWidth();
    }
}
