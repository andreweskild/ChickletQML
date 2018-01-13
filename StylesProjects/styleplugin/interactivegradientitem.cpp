#include "interactivegradientitem.h"


InteractiveGradientItem::InteractiveGradientItem(QQuickItem *p_parent) : QNanoQuickItem(p_parent),
    m_shape(InteractiveGradientItem::RoundedRect)
{
    setAcceptHoverEvents(true);
}

QColor InteractiveGradientItem::primaryColor() const
{
    return m_primaryColor;
}

void InteractiveGradientItem::setPrimaryColor(const QColor &p_primaryColor)
{
    if (m_primaryColor.rgba() != p_primaryColor.rgba())
    {
        m_primaryColor = p_primaryColor;
        update();
    }
}

QColor InteractiveGradientItem::secondaryColor() const
{
    return m_secondaryColor;
}

void InteractiveGradientItem::setSecondaryColor(const QColor &p_secondaryColor)
{
    if (m_secondaryColor.rgba() != p_secondaryColor.rgba())
    {
        m_secondaryColor = p_secondaryColor;
        update();
    }
}

InteractiveGradientItem::Shape InteractiveGradientItem::shape() const
{
    return m_shape;
}

void InteractiveGradientItem::setShape(const InteractiveGradientItem::Shape &p_shape)
{
    if(m_shape != p_shape)
    {
        m_shape = p_shape;
        update();
    }
}

QPointF InteractiveGradientItem::mousePosition() const
{
    return m_mousePos;
}

void InteractiveGradientItem::updateMousePosition(const QPointF &p_mousePos)
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
    return new InteractiveGradientPainter(m_shape);
}

InteractiveGradientPainter::InteractiveGradientPainter(const InteractiveGradientItem::Shape &p_shape) :
    m_shape(p_shape)
{
}


void InteractiveGradientPainter::paint(QNanoPainter *p)
{
    p->beginPath();
    switch(m_shape)
    {
        case InteractiveGradientItem::Rect:
        {
            p->rect(0, 0,
                    width(), height());
        }
        break;
        case InteractiveGradientItem::RoundedRect:
        {
            p->roundedRect(0, 0,
                           width(), height(), M_RADIUS);
        }
        break;
        case InteractiveGradientItem::Circle:
        {
            p->circle(width()*.5, height()*.5, width()*.5);
        }
        break;
    }
    if(width() > height())
    {
        m_gradient.setOuterRadius(width() * 2);
    }
    else
    {
        m_gradient.setOuterRadius(height() * 2);
    }
    m_gradient.setStartColor(m_primaryColor);
    m_gradient.setEndColor(m_secondaryColor);
    p->setFillStyle(m_gradient);
    p->fill();
}

void InteractiveGradientPainter::synchronize(QNanoQuickItem *p_item)
{
    InteractiveGradientItem *gradientItem = static_cast<InteractiveGradientItem *>(p_item);
    if(gradientItem)
    {
        m_primaryColor = QNanoColor::fromQColor(gradientItem->primaryColor());
        m_secondaryColor = QNanoColor::fromQColor(gradientItem->secondaryColor());
        m_gradient.setCenterPosition(gradientItem->mousePosition());
    }
}
