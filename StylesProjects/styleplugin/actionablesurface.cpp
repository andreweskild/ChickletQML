#include "actionablesurface.h"

ActionableSurface::ActionableSurface(QQuickItem *parent) : QQuickPaintedItem(parent),
    m_mainColor(Qt::red),
    m_mainGradientColor(Qt::yellow),
    m_secondaryGradientColor(Qt::yellow),
    m_gradientBorderColor(Qt::yellow),
    m_radius(0),
    m_gradientIntensity(0),
    m_border(new BorderGroup()),
    m_pressed(false)
{
    setAcceptHoverEvents(true);
    initAnimationEffects();
    initGradientEffect();
    connect(&m_hoverAnimation, SIGNAL(valueChanged(QVariant)), this, SLOT(receiveAnimValue(QVariant)));
    connect(this, SIGNAL(widthChanged()), this, SLOT(updateGradientSize()));
    connect(this, SIGNAL(isPressedChanged()), this, SLOT(handleMouseEvent()));

}

QColor ActionableSurface::mainColor() const
{
    return m_mainColor;
}

void ActionableSurface::setMainColor(const QColor p_mainColor)
{
    m_mainColor = p_mainColor;
}

QColor ActionableSurface::gradientBorderColor() const
{
    return m_gradientBorderColor;
}

void ActionableSurface::setGradientBorderColor(const QColor p_gradientBorderColor)
{
    m_gradientBorderColor = p_gradientBorderColor;
}

QColor ActionableSurface::mainGradientColor() const
{
    return m_mainGradientColor;
}

void ActionableSurface::setMainGradientColor(const QColor p_mainGradientColor)
{
    m_mainGradientColor = p_mainGradientColor;
    m_surfaceGradient->setColorAt(0, m_mainGradientColor);
    update();
}


QColor ActionableSurface::secondaryGradientColor() const
{
    return m_mainGradientColor;
}

void ActionableSurface::setSecondaryGradientColor(const QColor p_secondaryGradientColor)
{
    m_secondaryGradientColor = p_secondaryGradientColor;
    m_surfaceGradient->setColorAt(1, m_secondaryGradientColor);
    update();
}

QColor ActionableSurface::pressedColor() const
{
    return m_pressedColor;
}

void ActionableSurface::setPressedColor(const QColor p_pressedColor)
{
    m_pressedColor = p_pressedColor;
    update();
}

QColor ActionableSurface::pressedBorderColor() const
{
    return m_pressedBorderColor;
}

void ActionableSurface::setPressedBorderColor(const QColor p_pressedBorderColor)
{
    m_pressedBorderColor = p_pressedBorderColor;
    update();
}

bool ActionableSurface::isPressed() const
{
    return m_pressed;
}

void ActionableSurface::setIsPressed(const bool p_isPressed)
{
    m_pressed = p_isPressed;
    emit isPressedChanged();
}

void ActionableSurface::initGradientEffect()
{
    m_surfaceGradient = new QRadialGradient(QPointF(0,0), width() + width()/2);
    m_surfaceGradient->setColorAt(0, m_mainGradientColor);
    m_surfaceGradient->setColorAt(1, m_secondaryGradientColor);
}

void ActionableSurface::updateGradientSize()
{
    m_surfaceGradient->setRadius(width() + width()/2);
}


void ActionableSurface::updateGradientPos(QPointF p_center)
{
    m_surfaceGradient->setCenter(p_center);
    m_surfaceGradient->setFocalPoint(p_center);
}

void ActionableSurface::updateGradientColors(QColor p_main, QColor p_secondary)
{
    m_surfaceGradient->setColorAt(0, p_main);
    m_surfaceGradient->setColorAt(1, p_secondary);
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
    QQuickPaintedItem::setAntialiasing(true);
    QRectF rect(x() + .5, y() + .5, width() - 1, height() - 1);

    if(m_pressed)
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

        painter->setBrush(QBrush(m_mainColor));
    }

    painter->drawRoundedRect(rect,
                         m_radius - 1, m_radius - 1);

        painter->setOpacity(m_gradientIntensity);
        painter->setPen(QPen(
                        QBrush(m_gradientBorderColor),
                        m_border->width())
                    );

        painter->setBrush(*m_surfaceGradient);

        painter->drawRoundedRect(rect,
                             m_radius - 1, m_radius - 1);
}

void ActionableSurface::hoverEnterEvent(QHoverEvent *event)
{
    playAnimation();
    update();
}

void ActionableSurface::hoverLeaveEvent(QHoverEvent *event)
{
    playReverseAnimation();
    update();
}

void ActionableSurface::hoverMoveEvent(QHoverEvent *event)
{
    updateGradientPos(event->pos());
    update();
}


void ActionableSurface::handleMouseEvent()
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
    qInfo() << "fuck";
    playReverseAnimation();
}

void ActionableSurface::mouseRelease()
{
    playAnimation();
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
