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
    setRaised(M_GREYS_LIGHT.lighter(120));
    setWindow(M_GREYS_LIGHT.lighter(112));
    setSunken(M_GREYS_LIGHT);
    setSunkenDark(M_GREYS_LIGHT.darker(200));
    setContent(M_GREYS_LIGHT.darker(350));
    setContentSecondary(Qt::white);
}

void BasePalette::changeToDarkGreys()
{
    setRaised(M_GREYS_DARK.lighter(170));
    setWindow(M_GREYS_DARK.lighter(140));
    setSunken(M_GREYS_DARK);
    setSunkenDark(M_GREYS_DARK.darker(180));
    setContent(Qt::white);
    setContentSecondary(Qt::white);
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

void BasePalette::setAccentLight(const QColor &p_color)
{
    if(m_accentLight != p_color)
    {
        m_accentLight = p_color;
        emit accentLightChanged();
    }
}

QColor BasePalette::accent() const
{
    return m_accent;
}
void BasePalette::setAccent(const QColor &p_color)
{
    if(m_accent != p_color)
    {
        m_accent = p_color;
        emit accentChanged();
    }
}

QColor BasePalette::accentDark() const
{
    return m_accentDark;
}
void BasePalette::setAccentDark(const QColor &p_color)
{
    if(m_accentDark != p_color)
    {
        m_accentDark = p_color;
        emit accentDarkChanged();
    }
}


QColor BasePalette::dangerousLight() const
{
    return m_dangerousLight;
}
void BasePalette::setDangerousLight(const QColor &p_color)
{
    if(m_dangerousLight != p_color)
    {
        m_dangerousLight = p_color;
        emit dangerousLightChanged();
    }
}

QColor BasePalette::dangerous() const
{
    return m_dangerous;
}
void BasePalette::setDangerous(const QColor &p_color)
{
    if(m_dangerous != p_color)
    {
        m_dangerous = p_color;
        emit dangerousChanged();
    }
}


QColor BasePalette::dangerousDark() const
{
    return m_dangerousDark;
}
void BasePalette::setDangerousDark(const QColor &p_color)
{
    if(m_dangerousDark != p_color)
    {
        m_dangerousDark = p_color;
        emit dangerousDarkChanged();
    }
}


QColor BasePalette::raised() const
{
    return m_raised;
}
void BasePalette::setRaised(const QColor &p_color)
{
    if(m_raised != p_color)
    {
        m_raised = p_color;
        emit raisedChanged();
    }
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
void BasePalette::setSunken(const QColor &p_color)
{
    if(m_sunken != p_color)
    {
        m_sunken = p_color;
        emit sunkenChanged();
    }
}

QColor BasePalette::sunkenDark() const
{
    return m_sunkenDark;
}
void BasePalette::setSunkenDark(const QColor &p_color)
{
    if(m_sunkenDark != p_color)
    {
        m_sunkenDark = p_color;
        emit sunkenDarkChanged();
    }
}

QColor BasePalette::content() const
{
    return m_content;
}
void BasePalette::setContent(const QColor &p_color)
{
    if(m_content != p_color)
    {
        m_content = p_color;
        emit contentChanged();
    }
}

QColor BasePalette::contentSecondary() const
{
    return m_contentSecondary;
}
void BasePalette::setContentSecondary(const QColor &p_color)
{
    if(m_contentSecondary != p_color)
    {
        m_contentSecondary = p_color;
        emit contentSecondaryChanged();
    }
}

QColor BasePalette::shadow() const
{
    return m_shadow;
}
void BasePalette::setShadow(const QColor &p_color)
{
    if(m_shadow != p_color)
    {
        m_shadow = p_color;
        emit shadowChanged();
    }
}

