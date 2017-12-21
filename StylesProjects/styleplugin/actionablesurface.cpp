#include "actionablesurface.h"

ActionableSurface::ActionableSurface(QQuickItem *parent) : QQuickPaintedItem(parent),
    m_hovered(false),
    m_gradientIntensity(0),
    m_border(new BorderGroup()),
    m_pressed(false),
    m_drawPressed(false)
{
    QQuickPaintedItem::setAntialiasing(true);
    setAcceptHoverEvents(true);
    setMipmap(true);
    m_gradient = new GradientGroup();
}

void ActionableSurface::componentComplete()
{
    QQuickItem::componentComplete();
    updateGradient();
    initAnimationEffects();
    connect(&m_hoverAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(receiveAnimValue(QVariant)));
    connect(this, SIGNAL(pressedChanged()), this, SLOT(handleMousePressEvent()));
    connect(this, SIGNAL(hoveredChanged()), this, SLOT(handleMouseHoverEvent()));
}

QColor ActionableSurface::color() const
{
    return m_color;
}

void ActionableSurface::setColor(const QColor p_color)
{
    m_color = p_color;
}

QColor ActionableSurface::pressedColor() const
{
    return m_pressedColor;
}

void ActionableSurface::setPressedColor(const QColor p_pressedColor)
{
    m_pressedColor = p_pressedColor;
    emit pressedColorChanged();
}

QColor ActionableSurface::pressedBorderColor() const
{
    return m_pressedBorderColor;
}

void ActionableSurface::setPressedBorderColor(const QColor p_pressedBorderColor)
{
    m_pressedBorderColor = p_pressedBorderColor;
    emit pressedBorderColorChanged();
}

bool ActionableSurface::pressed() const
{
    return m_pressed;
}

void ActionableSurface::setPressed(const bool p_pressed)
{
    m_pressed = p_pressed;
    emit pressedChanged();
}

bool ActionableSurface::hovered() const
{
    return m_hovered;
}

void ActionableSurface::setHovered(const bool p_hovered)
{
    m_hovered = p_hovered;
    emit hoveredChanged();
}


void ActionableSurface::updateGradient()
{
    m_gradient->setSize(width() + width() * .5);
}


void ActionableSurface::updateGradientPos(QPointF p_center)
{
    m_gradient->setCenter(p_center);
    update();
}

void ActionableSurface::initAnimationEffects()
{
    m_hoverAnimation.setEasingCurve(QEasingCurve::InOutSine);
    m_hoverAnimation.setDuration(100);
    m_hoverAnimation.setStartValue(0.0);
    m_hoverAnimation.setEndValue(1.0);
}


void ActionableSurface::paint(QPainter *painter)
{
    QRectF rect(x() + 1, y() + 1, width() - 2, height() - 2);

    if(m_drawPressed)
    {
        painter->setPen(QPen(
                        QBrush(m_pressedBorderColor),
                        m_border->width())
                    );

        painter->setBrush(QBrush(m_pressedColor));
    }
    else
    {
        painter->setPen(QPen(
                        QBrush(m_border->color()),
                        m_border->width())
                    );

        painter->setBrush(QBrush(m_color));
    }

    painter->drawRoundedRect(rect.adjusted(0.5, 0.5, -0.5, -0.5),
                         m_radius - 1, m_radius - 1);


    painter->setOpacity(m_gradientIntensity);
    painter->setPen(QPen(
                    QBrush(m_gradient->border()->color()),
                    m_border->width())
                );

    painter->setBrush(*(m_gradient->gradient()));

    painter->drawRoundedRect(rect.adjusted(0.5, 0.5, -0.5, -0.5),
                         m_radius - 1, m_radius - 1);
}


void ActionableSurface::hoverMoveEvent(QHoverEvent *event)
{
    updateGradientPos(event->pos());
}



void ActionableSurface::handleMousePressEvent()
{
    if(m_pressed)
    {
        mousePress();
    }
    else
    {
        mouseRelease();
    }
}

void ActionableSurface::mousePress()
{
    if(m_drawPressed == false)
    {
        m_drawPressed = true;
    }
    if(m_hovered)
    {
        playReverseAnimation();
    }
}

void ActionableSurface::mouseRelease()
{
    if(m_hovered)
    {
        playAnimation();
    }
}

void ActionableSurface::handleMouseHoverEvent()
{
    if(m_hovered)
    {
        hoverEnter();
    }
    else
    {
        hoverExit();
    }
}

void ActionableSurface::hoverEnter()
{
    playAnimation();
}

void ActionableSurface::hoverExit()
{
    if(m_drawPressed == true)
    {
        m_drawPressed = false;
    }
    playReverseAnimation();
}

void ActionableSurface::receiveAnimValue(QVariant p_newValue)
{
    m_gradientIntensity = p_newValue.toFloat();
    update();
}

void ActionableSurface::playAnimation()
{
    if(m_hoverAnimation.state() == BasicAnimator::Running)
    {
        qreal tempTime;
        m_hoverAnimation.pause();
        tempTime = m_hoverAnimation.currentTime();
        m_hoverAnimation.setDirection(BasicAnimator::Forward);
        m_hoverAnimation.setCurrentTime(tempTime);
    }
    else
    {
        m_hoverAnimation.setDirection(BasicAnimator::Forward);
    }
    m_hoverAnimation.start();
}

void ActionableSurface::playReverseAnimation()
{
    if(m_hoverAnimation.state() == BasicAnimator::Running)
    {
        qreal tempTime;
        m_hoverAnimation.pause();
        tempTime = m_hoverAnimation.currentTime();
        m_hoverAnimation.setDirection(BasicAnimator::Backward);
        m_hoverAnimation.setCurrentTime(tempTime);
    }
    else
    {
        m_hoverAnimation.setDirection(BasicAnimator::Backward);
    }
    m_hoverAnimation.start();
}
