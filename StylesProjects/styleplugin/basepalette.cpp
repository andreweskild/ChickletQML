#include "basepalette.h"

BasePalette::BasePalette(QObject *parent) : QObject(parent)
{
    initColors();
}

void BasePalette::initColors()
{
    m_primaryLight = m_primaryHue.lighter(120);
    m_primaryMid = m_primaryHue.darker(120);
    m_primaryDark = m_primaryHue.darker(160);

    m_dangerousLight = m_dangerousHue.lighter(120);
    m_dangerousMid = m_dangerousHue.darker(120);
    m_dangerousDark = m_dangerousHue.darker(140);

    m_greyWhite = Qt::white;
    m_greyLight = m_greyHue.lighter(140);
    m_greyMidLight = m_greyHue.lighter(112);
    m_greyMidDark = m_greyHue.darker(140);
    m_greyDark = m_greyHue.darker(200);
    m_greyBlack = m_greyHue.darker(350);

    m_shadow = QColor(0, 0, 0, 70);
}


// PRIMARY COLOR GETTERS ==============
QColor BasePalette::primaryLight() const
{
    return m_primaryLight;
}

QColor BasePalette::primaryNormal() const
{
    return m_primaryHue;
}

QColor BasePalette::primaryMid() const
{
    return m_primaryMid;
}

QColor BasePalette::primaryDark() const
{
    return m_primaryDark;
}


//DANGEROUS COLOR GETTERS ===============
QColor BasePalette::dangerousLight() const
{
    return m_dangerousLight;
}

QColor BasePalette::dangerousNormal() const
{
    return m_dangerousHue;
}

QColor BasePalette::dangerousMid() const
{
    return m_dangerousMid;
}

QColor BasePalette::dangerousDark() const
{
    return m_dangerousDark;
}


//GREY COLOR GETTERS ===============
QColor BasePalette::greyWhite() const
{
    return m_greyWhite;
}

QColor BasePalette::greyLight() const
{
    return m_greyLight;
}

QColor BasePalette::greyMidLight() const
{
    return m_greyMidLight;
}

QColor BasePalette::greyMid() const
{
    return m_greyHue;
}

QColor BasePalette::greyMidDark() const
{
    return m_greyMidDark;
}

QColor BasePalette::greyDark() const
{
    return m_greyDark;
}

QColor BasePalette::greyBlack() const
{
    return m_greyBlack;
}


// SHADOW COLOR GETTER ==============
QColor BasePalette::shadow() const
{
    return m_shadow;
}

