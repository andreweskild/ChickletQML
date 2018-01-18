#include "basepalette.h"

BasePalette::BasePalette(QObject *parent) : QObject(parent)
{
    initColors();
}


void BasePalette::initColors()
{
    m_accentLight = M_ACCENT.lighter(120);
    m_accent = M_ACCENT;
    m_accentDark = M_ACCENT.darker(120);

    m_dangerousLight = M_DANGEROUS.lighter(120);
    m_dangerous = M_DANGEROUS;
    m_dangerousDark = M_DANGEROUS.darker(120);
    m_shadow = QColor(0, 0, 0, 40);

    updateGreys();
}

void BasePalette::updateGreys()
{
    if(m_dark)
    {
        changeToDarkGreys();
    }
    else
    {
        changeToLightGreys();
    }
}

void BasePalette::changeToLightGreys()
{
    m_raised = M_GREYS_LIGHT.lighter(120);
    setWindow(M_GREYS_LIGHT.lighter(112));
    m_sunken = M_GREYS_LIGHT;
    m_sunkenDark = M_GREYS_LIGHT.darker(200);
    m_content = M_GREYS_LIGHT.darker(350);
    m_contentSecondary = Qt::white;
}

void BasePalette::changeToDarkGreys()
{
    m_raised = M_GREYS_DARK.lighter(170);
    setWindow(M_GREYS_DARK.lighter(140));
    m_sunken = M_GREYS_DARK;
    m_sunkenDark = M_GREYS_DARK.darker(180);
    m_content = Qt::white;
    m_contentSecondary = Qt::white;
}


bool BasePalette::dark() const
{
    return m_dark;
}

void BasePalette::setDark(const bool &p_isDark)
{
    if (m_dark != p_isDark)
    {
        m_dark = p_isDark;
        emit darkChanged();
        updateGreys();
    }
}


QColor BasePalette::accentLight() const
{
    return m_accentLight;
}

QColor BasePalette::accent() const
{
    return m_accent;
}

QColor BasePalette::accentDark() const
{
    return m_accentDark;
}


QColor BasePalette::dangerousLight() const
{
    return m_dangerousLight;
}

QColor BasePalette::dangerous() const
{
    return m_dangerous;
}


QColor BasePalette::dangerousDark() const
{
    return m_dangerousDark;
}


QColor BasePalette::raised() const
{
    return m_raised;
}

QColor BasePalette::window() const
{
    return m_window;
}

void BasePalette::setWindow(const QColor &p_color)
{
    if(m_window != p_color)
    {
        m_window = p_color;
        emit windowChanged();
    }
}

QColor BasePalette::sunken() const
{
    return m_sunken;
}

QColor BasePalette::sunkenDark() const
{
    return m_sunkenDark;
}

QColor BasePalette::content() const
{
    return m_content;
}

QColor BasePalette::contentSecondary() const
{
    return m_contentSecondary;
}

QColor BasePalette::shadow() const
{
    return m_shadow;
}

