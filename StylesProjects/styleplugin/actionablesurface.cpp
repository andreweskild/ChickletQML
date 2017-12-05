#include "actionablesurface.h"

ActionableSurface::ActionableSurface(QQuickItem *parent) : QQuickPaintedItem(parent),
    m_mainColor(Qt::red),
    m_secondaryColor(Qt::black),
    m_mainActiveColor(Qt::red),
    m_secondaryActiveColor(Qt::black),
    m_activeBorderColor(Qt::yellow),
    m_radius(0),
    m_border(new BorderGroup()),
    m_hovered(false)
{
    setAcceptHoverEvents(true);
}

QColor ActionableSurface::mainColor() const
{
    return m_mainColor;
}

void ActionableSurface::setMainColor(const QColor p_mainColor)
{
    m_mainColor = p_mainColor;
}

QColor ActionableSurface::secondaryColor() const
{
    return m_mainColor;
}

void ActionableSurface::setSecondaryColor(const QColor p_secondaryColor)
{
    m_secondaryColor = p_secondaryColor;
}


QColor ActionableSurface::mainActiveColor() const
{
    return m_mainActiveColor;
}

void ActionableSurface::setMainActiveColor(const QColor p_mainActiveColor)
{
    m_mainActiveColor = p_mainActiveColor;
    update();
}

QColor ActionableSurface::secondaryActiveColor() const
{
    return m_mainActiveColor;
}

void ActionableSurface::setSecondaryActiveColor(const QColor p_secondaryActiveColor)
{
    m_secondaryActiveColor = p_secondaryActiveColor;
    update();
}


QColor ActionableSurface::activeBorderColor() const
{
    return m_activeBorderColor;
}

void ActionableSurface::setActiveBorderColor(const QColor p_activeBorderColor)
{
    m_activeBorderColor = p_activeBorderColor;
}

void ActionableSurface::initGradientEffect(QPointF p_center)
{
    m_surfaceGradient = new QRadialGradient(p_center, width() + width()/2);
    m_surfaceGradient->setColorAt(0, m_mainActiveColor);
    m_surfaceGradient->setColorAt(1, m_secondaryActiveColor);
}

void ActionableSurface::paint(QPainter *painter)
{
    QQuickPaintedItem::setAntialiasing(true);
    qreal borderClippingAdjustment = m_border->width() / 2;
    if (opacity() > 0)
    {
        painter->setPen(QPen(
                        QBrush(m_activeBorderColor),
                        m_border->width())
                    );
        painter->setBrush(*m_surfaceGradient);
    }

    QRectF rect(x() + .5, y() + .5, width() - 1, height() - 1);

    painter->drawRoundedRect(rect,
                         m_radius - 1, m_radius - 1);
}

void ActionableSurface::hoverEnterEvent(QHoverEvent *event)
{
    initGradientEffect(event->pos());
    m_hovered = true;
    update();
}

void ActionableSurface::hoverLeaveEvent(QHoverEvent *event)
{
    m_hovered = false;
    update();
}

void ActionableSurface::hoverMoveEvent(QHoverEvent *event)
{
    m_surfaceGradient->setCenter(event->pos());
    m_surfaceGradient->setFocalPoint(event->pos());
    update();
}
