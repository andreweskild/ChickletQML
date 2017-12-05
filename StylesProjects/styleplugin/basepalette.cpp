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
}

QColor BasePalette::activeMain() const
{
    return m_activeMain;
}

QColor BasePalette::activeHighlight() const
{
    return m_activeHighlight;
}

QColor BasePalette::activeDark() const
{
    return m_activeDark;
}

QColor BasePalette::activeDarkest() const
{
    return m_activeDarkest;
}

QColor BasePalette::dangerMain() const
{
    return m_dangerMain;
}

QColor BasePalette::dangerHighlight() const
{
    return m_dangerHighlight;
}

QColor BasePalette::dangerDark() const
{
    return m_dangerDark;
}

QColor BasePalette::dangerDarkest() const
{
    return m_dangerDarkest;
}

QColor BasePalette::disabledMain() const
{
    return m_disabledMain;
}

QColor BasePalette::disabledDark() const
{
    return m_disabledDark;
}

QColor BasePalette::actionableMain() const
{
    return m_actionableMain;
}

QColor BasePalette::actionableDark() const
{
    return m_actionableDark;
}

QColor BasePalette::actionableDarkest() const
{
    return m_actionableDarkest;
}

QColor BasePalette::structureBase() const
{
    return m_structureBase;
}

QColor BasePalette::structureMidGround() const
{
    return m_structureMidGround;
}

QColor BasePalette::structureTitlebar() const
{
    return m_structureTitlebar;
}

QColor BasePalette::structureBorder() const
{
    return m_structureBorder;
}

QColor BasePalette::textLight() const
{
    return m_textLight;
}

QColor BasePalette::textDark() const
{
    return m_textDark;
}

QColor BasePalette::shadow() const
{
    return m_shadow;
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
    m_structureTitlebar = QColor(204, 204, 204);
    m_structureBorder = QColor(158, 158, 158);

    m_textLight = QColor(250, 250, 250);
    m_textDark = QColor(20, 20, 20);

    m_shadow = QColor(200, 200, 200);
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
    m_structureTitlebar = QColor(204, 204, 204);
    m_structureBorder = QColor(158, 158, 158);

    m_textLight = QColor(250, 250, 250);
    m_textDark = QColor(20, 20, 20);

    m_shadow = QColor(0, 0, 0, 70);
}
