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
    m_activeMain = QColor(60, 204, 147);
    m_activeHighlight = QColor(133, 223, 172);
    m_activeDark = QColor(51, 152, 112);
    m_activeDarkest = QColor(20, 82, 57);

    m_dangerMain = QColor(255, 51, 127);
    m_dangerHighlight = QColor(255, 103, 160);
    m_dangerDark = QColor(192, 40, 136);
    m_dangerDarkest = QColor(148, 38, 124);

    m_disabledMain = QColor(204, 204, 204);
    m_disabledDark = QColor(153, 153, 153);

    m_actionableMain = QColor(250, 250, 250);
    m_actionableDark = QColor(103, 103, 103);
    m_actionableDarkest = QColor(63, 63, 63);

    m_structureBase = QColor(230, 230, 230);
    m_structureMidGround = QColor(240, 240, 240);
    m_structureLowGround = QColor(204, 204, 204);
    m_structureBorder = QColor(158, 158, 158);

    m_textLight = QColor(250, 250, 250);
    m_textDark = QColor(20, 20, 20);

    m_shadow = QColor(0, 0, 0, 30);
}

void BasePalette::initThemeDark()
{
    m_activeMain = QColor(133, 223, 172);
    m_activeHighlight = QColor(133, 223, 172);
    m_activeDark = QColor(51, 152, 112);
    m_activeDarkest = QColor(20, 82, 57);

    m_dangerMain = QColor(255, 51, 127);
    m_dangerHighlight = QColor(133, 223, 172);
    m_dangerDark = QColor(192, 40, 136);
    m_dangerDarkest = QColor(148, 38, 124);

    m_disabledMain = QColor(204, 204, 204);
    m_disabledDark = QColor(153, 153, 153);

    m_actionableMain = QColor(250, 250, 250);
    m_actionableDark = QColor(103, 103, 103);
    m_actionableDarkest = QColor(63, 63, 63);

    m_structureBase = QColor(230, 230, 230);
    m_structureMidGround = QColor(240, 240, 240);
    m_structureLowGround = QColor(204, 204, 204);
    m_structureBorder = QColor(158, 158, 158);

    m_textLight = QColor(250, 250, 250);
    m_textDark = QColor(20, 20, 20);

    m_shadow = QColor(0, 0, 0, 70);
}
