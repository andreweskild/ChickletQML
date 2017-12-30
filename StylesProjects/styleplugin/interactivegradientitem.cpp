#include "interactivegradientitem.h"


InteractiveGradientPainter::InteractiveGradientPainter() :
    m_dimensions(new DimensionsProvider)
{
}

void InteractiveGradientPainter::paint(QNanoPainter *p)
{
    p->setAntialias(1.1);
    p->beginPath();
    switch(m_geometryMode)
    {
        case InteractiveGradientItem::RoundedRect:
        {
            p->setPixelAlign(QNanoPainter::PIXEL_ALIGN_HALF);
            p->roundedRect(0, 0, width() - 1, height() - 1, m_dimensions->property("actionableRadius").toInt());
        }
        break;
        case InteractiveGradientItem::Circle:
        {
            p->circle(width()*.5, height()*.5, width()*.5 - .5);
        }
        break;
        case InteractiveGradientItem::Rect:
        {
            p->setPixelAlign(QNanoPainter::PIXEL_ALIGN_HALF);
            p->rect(0, 0, width() - 1, height() - 1);
        }
    }
    m_gradient.setOuterRadius(width()*2);
    if (m_primaryColor == m_secondaryColor)
    {
        p->setFillStyle(QNanoColor::fromQColor(m_primaryColor));
    }
    else
    {
        m_gradient.setStartColor(QNanoColor::fromQColor(m_primaryColor));
        m_gradient.setEndColor(QNanoColor::fromQColor(m_secondaryColor));
        p->setFillStyle(m_gradient);
    }
    p->fill();
    p->setStrokeStyle(m_borderColor);
    p->setLineWidth(m_dimensions->property("borderWidth").toInt());
    p->stroke();
}

void InteractiveGradientPainter::synchronize(QNanoQuickItem *p_item)
{
    InteractiveGradientItem *gradientItem = static_cast<InteractiveGradientItem *>(p_item);
    if(gradientItem)
    {
        m_borderColor = QNanoColor::fromQColor(gradientItem->borderColor());
        m_primaryColor = gradientItem->primaryColor();
        m_secondaryColor = gradientItem->secondaryColor();
        m_gradient.setCenterPosition(gradientItem->mousePosition());
        m_geometryMode = static_cast<InteractiveGradientItem::GeometryMode>(gradientItem->property("geometryMode").toInt());
    }
}

InteractiveGradientItem::InteractiveGradientItem(QQuickItem *p_parent) : QNanoQuickItem(p_parent),
    m_palette(new BasePalette(this)),
    m_pressed(false),
    m_hovered(false),
    m_group(new QParallelAnimationGroup),
    m_primaryAnimation(new QPropertyAnimation(this, "primaryColor")),
    m_secondaryAnimation(new QPropertyAnimation(this, "secondaryColor")),
    m_borderAnimation(new QPropertyAnimation(this, "borderColor"))
{
    setAcceptHoverEvents(true);
    m_primaryColor = m_palette->greyLight();
    m_secondaryColor = m_palette->greyLight();
    m_borderColor = m_palette->greyMidDark();
    initAnimations();

    connect(this, SIGNAL(hoveredChanged()), this, SLOT(handleHover()));
    connect(this, SIGNAL(pressedChanged()), this, SLOT(handleMousePress()));
}

QColor InteractiveGradientItem::borderColor() const
{
    return m_borderColor;
}

void InteractiveGradientItem::setBorderColor(const QColor &p_borderColor)
{
    if (m_borderColor.rgba() != p_borderColor.rgba())
    {
        m_borderColor = p_borderColor;
        update();
    }
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

void InteractiveGradientItem::handleHover()
{
    if(m_hovered && !m_pressed)
    {
        handleAnimation(Hovered);
    }
    else if(!m_pressed)
    {
        handleAnimation(Normal);
    }
}


void InteractiveGradientItem::handleMousePress()
{
    if (m_pressed)
    {
        handleAnimation(Pressed);
    }
    else
    {
        if(m_hovered)
        {
            handleAnimation(Hovered);
        }
        else
        {
            handleAnimation(Normal);
        }
    }
}

QNanoQuickItemPainter *InteractiveGradientItem::createItemPainter() const
{
    return new InteractiveGradientPainter();
}

void InteractiveGradientItem::initAnimations()
{
    m_primaryAnimation->setDuration(ANIM_DURATION);
    m_primaryAnimation->setEasingCurve(ANIM_EASING);

    m_secondaryAnimation->setDuration(ANIM_DURATION);
    m_secondaryAnimation->setEasingCurve(ANIM_EASING);

    m_borderAnimation->setDuration(ANIM_DURATION);
    m_borderAnimation->setEasingCurve(ANIM_EASING);

    m_group->addAnimation(m_primaryAnimation);
    m_group->addAnimation(m_secondaryAnimation);
    m_group->addAnimation(m_borderAnimation);
}

void InteractiveGradientItem::handleAnimation(State p_state)
{
    switch(p_state)
    {
        case Normal:
        {
            m_primaryAnimation->setEndValue(m_palette->greyLight());
            m_secondaryAnimation->setEndValue(m_palette->greyLight());
            m_borderAnimation->setEndValue(m_palette->greyMidDark());
            m_group->start();
        }
        break;
        case Hovered:
        {
            m_primaryAnimation->setEndValue(m_palette->primaryNormal());
            m_secondaryAnimation->setEndValue(m_palette->primaryLight());
            m_borderAnimation->setEndValue(m_palette->primaryMid());
            m_group->start();
        }
        break;
        case Pressed:
        {
            m_primaryAnimation->setEndValue(m_palette->primaryMid());
            m_secondaryAnimation->setEndValue(m_palette->primaryNormal());
            m_borderAnimation->setEndValue(m_palette->primaryDark());
            m_group->start();
        }
        break;
    }
}

