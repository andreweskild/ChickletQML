#include "interactivegradientitem.h"


InteractiveGradientPainter::InteractiveGradientPainter(const Shape &p_shape) :
    m_dimensions(new DimensionsProvider()),
    m_borderWidth(m_dimensions->property("borderWidth").toInt()),
    m_radius(m_dimensions->property("actionableRadius").toInt()),
    m_shape(p_shape)
{
}

InteractiveGradientPainter::~InteractiveGradientPainter()
{
    delete m_dimensions;
}

void InteractiveGradientPainter::paint(QNanoPainter *p)
{
    qreal borderAdjustment = m_borderWidth * .5;
    p->beginPath();
    switch(m_shape)
    {
        case Rect:
        {
            p->rect(borderAdjustment, borderAdjustment,
                    width() - m_borderWidth, height() - m_borderWidth);
        }
        break;
        case RoundedRect:
        {
            p->roundedRect(borderAdjustment, borderAdjustment,
                           width() - m_borderWidth, height() - m_borderWidth, m_radius);
        }
        break;
        case Circle:
        {
            p->circle(width()*.5, height()*.5, width()*.5 - borderAdjustment);
        }
        break;
    }
    m_gradient.setOuterRadius(width()*2);
    m_gradient.setStartColor(m_primaryColor);
    m_gradient.setEndColor(m_secondaryColor);
    p->setFillStyle(m_gradient);
    p->fill();
    p->setStrokeStyle(m_primaryColor);
    p->setLineWidth(m_borderWidth);
    p->stroke();
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

InteractiveGradientItem::InteractiveGradientItem(QQuickItem *p_parent) : QNanoQuickItem(p_parent),
    m_palette(new BasePalette(this)),
    m_pressed(false),
    m_hovered(false),
    m_group(new QParallelAnimationGroup(this)),
    m_primaryAnimation(new QPropertyAnimation(this, "primaryColor", this)),
    m_secondaryAnimation(new QPropertyAnimation(this, "secondaryColor", this))
{
    setAcceptHoverEvents(true);
    initAnimations();
    connect(this, SIGNAL(hoveredChanged()), this, SLOT(handleHover()));
    connect(this, SIGNAL(pressedChanged()), this, SLOT(handleMousePress()));
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

    m_group->addAnimation(m_primaryAnimation);
    m_group->addAnimation(m_secondaryAnimation);
}

void InteractiveGradientItem::handleAnimation(State p_state)
{
    if(m_group->state() == QParallelAnimationGroup::Running)
    {
        m_group->stop();
    }
    switch(p_state)
    {
        case Normal:
        {
            m_primaryAnimation->setEndValue(m_palette->greyLight());
            m_secondaryAnimation->setEndValue(m_palette->greyLight());
            m_group->start();
        }
        break;
        case Hovered:
        {
            m_primaryAnimation->setEndValue(m_palette->primaryNormal());
            m_secondaryAnimation->setEndValue(m_palette->primaryLight());
            m_group->start();
        }
        break;
        case Pressed:
        {
            m_primaryAnimation->setEndValue(m_palette->primaryMid());
            m_secondaryAnimation->setEndValue(m_palette->primaryNormal());
            m_group->start();
        }
        break;
    }
}

