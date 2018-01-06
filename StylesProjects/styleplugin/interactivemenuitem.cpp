#include "interactivemenuitem.h"

InteractiveMenuItem::InteractiveMenuItem(QQuickItem *p_parent) : InteractiveGradientItem(p_parent)
{
    m_primaryColor = m_palette->greyLight();
    m_secondaryColor = m_palette->greyLight();
}

QNanoQuickItemPainter *InteractiveMenuItem::createItemPainter() const
{
    return new InteractiveGradientPainter(InteractiveGradientPainter::Rect);
}

