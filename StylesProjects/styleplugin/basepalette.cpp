#include "basepalette.h"

BasePalette::BasePalette(ColorTheme p_colorTheme, QObject *parent) : QObject(parent),
    m_currentColorTheme(p_colorTheme)
{
    updateColors();
}

BasePalette::ColorTheme BasePalette::currentColorTheme()
{
    return m_currentColorTheme;
}

void BasePalette::setCurrentColorTheme(ColorTheme p_newColorTheme)
{
    m_currentColorTheme = p_newColorTheme;
    updateColors();
}

void BasePalette::updateColors()
{
    if (m_currentColorTheme == Light)
    {
        initThemeLight();
    }
    else
    {
        initThemeDark();
    }
}

void BasePalette::initThemeLight()
{
    m_activeLight = QColor::fromRgb(133, 223, 172);
    m_activeNormal = QColor::fromRgb(60, 204, 147);
    m_activeDark = QColor::fromRgb(45, 161, 114);
    m_activeDarkest = QColor::fromRgb(20, 82, 57);

    m_cautionLight = QColor::fromRgb(255, 103, 160);
    m_cautionNormal = QColor::fromRgb(255, 51, 127);
    m_cautionDark = QColor::fromRgb(191, 40, 136);
    m_cautionDarkest = QColor::fromRgb(148, 38, 124);

    m_greyWhite = Qt::white;
    m_greyLight = QColor::fromRgb(240, 238, 241);
    m_greyMedium = QColor::fromRgb(229, 227, 232);
    m_greyDark = QColor::fromRgb(204, 200, 208);
    m_greyDarkest = QColor::fromRgb(153, 145, 161);
    m_greyBlack = QColor::fromRgb(51, 47, 55);

    m_shadow = QColor(0, 0, 0, 50);
}

void BasePalette::initThemeDark()
{
}
