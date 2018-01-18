#include "palette.h"

PaletteAttached::PaletteAttached(QObject *p_parent) : QObject(p_parent)
{

}

Palette::Palette(QObject *parent) : QObject(parent)
{

}

PaletteAttached *Palette::qmlAttachedProperties(QObject *p_parent)
{
    return new PaletteAttached(p_parent);
}
