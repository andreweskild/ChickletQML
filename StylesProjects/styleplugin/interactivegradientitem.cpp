#include "interactivegradientitem.h"


InteractiveGradientPainter::InteractiveGradientPainter()
{
}

void InteractiveGradientPainter::paint(QNanoPainter *p)
{
    p->setAntialias(1.2);
    p->setPixelAlign(QNanoPainter::PIXEL_ALIGN_HALF);
    p->beginPath();
    p->roundedRect(1, 1, width() - 2, height() - 2, 4);
    m_gradient.setOuterRadius(width() * 0.5 + width());
    p->setFillStyle(m_gradient);
    p->fill();
    p->setStrokeStyle(QNanoColor::fromQColor(m_borderColor));
    p->setLineWidth(m_borderWidth);
    p->stroke();
}

void InteractiveGradientPainter::synchronize(QNanoQuickItem *p_item)
{
    InteractiveGradientItem *gradientItem = static_cast<InteractiveGradientItem *>(p_item);
    if(gradientItem)
    {
        m_borderColor = gradientItem->border()->color();
        m_borderWidth = gradientItem->border()->width();
        m_gradient.setStartColor(QNanoColor::fromQColor(gradientItem->primaryColor()));
        m_gradient.setEndColor(QNanoColor::fromQColor(gradientItem->secondaryColor()));
        m_gradient.setCenterPosition(gradientItem->mousePosition());
    }
}

InteractiveGradientItem::InteractiveGradientItem(QQuickItem *p_parent) : QNanoQuickItem(p_parent)
{
    setAcceptHoverEvents(true);
}

BorderGroup *InteractiveGradientItem::border()
{
    if (m_border == nullptr)
    {
        m_border = new BorderGroup();
    }
    return m_border;
}

QColor InteractiveGradientItem::primaryColor() const
{
    return m_primaryColor;
}

void InteractiveGradientItem::setPrimaryColor(const QColor p_primaryColor)
{
    if (m_primaryColor.rgba() != p_primaryColor.rgba())
    {
        m_primaryColor = p_primaryColor;
        emit primaryColorChanged();
        update();
    }
}

QColor InteractiveGradientItem::secondaryColor() const
{
    return m_secondaryColor;
}

void InteractiveGradientItem::setSecondaryColor(const QColor p_secondaryColor)
{
    if (m_secondaryColor.rgba() != p_secondaryColor.rgba())
    {
        m_secondaryColor = p_secondaryColor;
        emit secondaryColorChanged();
        update();
    }
}

QPointF InteractiveGradientItem::mousePosition() const
{
    return m_mousePos;
}

void InteractiveGradientItem::updateMousePosition(const QPointF p_mousePos)
{
    m_mousePos = p_mousePos;
    update();
}

void InteractiveGradientItem::hoverMoveEvent(QHoverEvent *p_event)
{
    updateMousePosition(p_event->posF());
}


QNanoQuickItemPainter *InteractiveGradientItem::createItemPainter() const
{
    return new InteractiveGradientPainter();
}
