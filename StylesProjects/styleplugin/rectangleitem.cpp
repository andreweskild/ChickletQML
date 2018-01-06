#include "rectangleitem.h"


RectanglePainter::RectanglePainter() :
    m_dimensions(new DimensionsProvider()),
    m_borderWidth(m_dimensions->property("borderWidth").toInt())
{
}

RectanglePainter::~RectanglePainter()
{
    delete m_dimensions;
}

void RectanglePainter::paint(QNanoPainter *p)
{
    qreal borderAdjustment = m_borderWidth * .5;
    p->beginPath();
    p->roundedRect(borderAdjustment, borderAdjustment,
                   width() - m_borderWidth, height() - m_borderWidth, 4);
    p->setFillStyle(QNanoColor::fromQColor(m_primaryColor));
    p->fill();
    p->setStrokeStyle(m_borderColor);
    p->setLineWidth(m_borderWidth);
    p->stroke();
}

void RectanglePainter::synchronize(QNanoQuickItem *p_item)
{
    RectangleItem *rectItem = static_cast<RectangleItem *>(p_item);
    if(rectItem)
    {
        m_borderColor = QNanoColor::fromQColor(rectItem->borderColor());
        m_primaryColor = rectItem->primaryColor();
    }
}

RectangleItem::RectangleItem(QQuickItem *p_parent) : QNanoQuickItem(p_parent),
    m_palette(new BasePalette(this)),
    m_borderAnimation(new QPropertyAnimation(this, "borderColor"))
{
    m_primaryColor = m_palette->greyLight();
    m_borderColor = m_palette->greyLight();
    initAnimations();

    connect(this, SIGNAL(hoveredChanged()), this, SLOT(handleHover()));
    connect(this, SIGNAL(pressedChanged()), this, SLOT(handleMousePress()));
}

QColor RectangleItem::borderColor() const
{
    return m_borderColor;
}


QColor RectangleItem::primaryColor() const
{
    return m_primaryColor;
}

void RectangleItem::setPrimaryColor(const QColor &p_primaryColor)
{
    if (m_primaryColor.rgba() != p_primaryColor.rgba())
    {
        m_primaryColor = p_primaryColor;
        update();
    }
}

void RectangleItem::setBorderColor(const QColor &p_borderColor)
{
    if (m_borderColor.rgba() != p_borderColor.rgba())
    {
        m_borderColor = p_borderColor;
        update();
    }
}


void RectangleItem::handleHover()
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

void RectangleItem::handleMousePress()
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

QNanoQuickItemPainter *RectangleItem::createItemPainter() const
{
    return new RectanglePainter();
}

void RectangleItem::initAnimations()
{
    m_borderAnimation->setDuration(ANIM_DURATION);
    m_borderAnimation->setEasingCurve(ANIM_EASING);
}


void RectangleItem::handleAnimation(State p_state)
{
    switch(p_state)
    {
        case Normal:
        {
            m_borderAnimation->setEndValue(m_palette->greyWhite());
            m_borderAnimation->start();
        }
        break;
        case Hovered:
        {
            m_borderAnimation->setEndValue(m_palette->primaryNormal());
            m_borderAnimation->start();
        }
        break;
        case Pressed:
        {
            m_borderAnimation->setEndValue(m_palette->primaryMid());
            m_borderAnimation->start();
        }
        break;
    }
}
