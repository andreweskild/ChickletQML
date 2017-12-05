#include "bordergroup.h"

BorderGroup::BorderGroup(QObject *parent) : QObject(parent),
    m_width(1),
    m_color(Qt::black)
{
}

BorderGroup *BorderGroup::qmlAttachedProperties(QObject *object)
{
    return new BorderGroup(object);
}

int BorderGroup::width() const
{
    return m_width;
}

QColor BorderGroup::color() const
{
    return m_color;
}
