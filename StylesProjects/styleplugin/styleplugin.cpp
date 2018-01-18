#include "styleplugin.h"

StylePlugin::StylePlugin(QObject *parent):
    QObject(parent),
    m_basePalette(new BasePalette(this)),
    m_dimensions(new DimensionsProvider(this))
{
}

StylePlugin::~StylePlugin()
{
}

StylePlugin *StylePlugin::qmlAttachedProperties(QObject *object)
{
    return new StylePlugin(object);
}


BasePalette* StylePlugin::palette() const
{
    return m_basePalette;
}

DimensionsProvider* StylePlugin::dimensions() const
{
    return m_dimensions;
}
