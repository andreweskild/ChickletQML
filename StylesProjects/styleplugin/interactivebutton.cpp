#include "interactivebutton.h"

InteractiveButton::InteractiveButton(QQuickItem *p_parent) : InteractiveGradientItem(p_parent)
{
    m_primaryColor = m_palette->greyLight();
    m_secondaryColor = m_palette->greyLight();
}

QNanoQuickItemPainter *InteractiveButton::createItemPainter() const
{
    return new InteractiveGradientPainter(InteractiveGradientPainter::RoundedRect);
}
