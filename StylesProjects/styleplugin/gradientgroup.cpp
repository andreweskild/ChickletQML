#include "gradientgroup.h"

GradientGroup::GradientGroup(QObject *parent) : QObject(parent),
    m_border(new BorderGroup())
{
    m_gradient = new QRadialGradient(QPointF(0, 0), 0);
}


QColor GradientGroup::mainColor() const
{
    return m_mainColor;
}

void GradientGroup::setMainColor(const QColor p_mainColor)
{
    m_gradient->setColorAt(0, p_mainColor);
    emit gradientChanged();
}

QColor GradientGroup::secondaryColor() const
{
    return m_secondaryColor;
}


void GradientGroup::setSecondaryColor(const QColor p_secondaryColor)
{
    m_gradient->setColorAt(1, p_secondaryColor);
    emit gradientChanged();
}

BorderGroup* GradientGroup::border() const
{
    return m_border;
}

void GradientGroup::setSize(const qreal p_size)
{
    m_gradient->setRadius(p_size);
    emit gradientChanged();
}


void GradientGroup::setCenter(const QPointF p_center)
{
    m_gradient->setCenter(p_center);
    m_gradient->setFocalPoint(p_center);
    emit gradientChanged();
}

QRadialGradient *GradientGroup::gradient() const
{
    return m_gradient;
}
