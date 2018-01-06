#include "interactiveroundbutton.h"

InteractiveRoundButton::InteractiveRoundButton(QQuickItem *p_parent) : InteractiveGradientItem(p_parent)
{
    m_primaryColor = m_palette->greyLight();
    m_secondaryColor = m_palette->greyLight();
}

QNanoQuickItemPainter *InteractiveRoundButton::createItemPainter() const
{
    return new InteractiveGradientPainter(InteractiveGradientPainter::Circle);
}
