#ifndef BASEPALETTE_H
#define BASEPALETTE_H

#include <QObject>
#include <QColor>

class BasePalette : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor activeLight MEMBER m_activeLight NOTIFY activeLightChanged)
    Q_PROPERTY(QColor activeNormal MEMBER m_activeNormal NOTIFY activeNormalChanged)
    Q_PROPERTY(QColor activeDark MEMBER m_activeDark NOTIFY activeDarkChanged)
    Q_PROPERTY(QColor activeDarkest MEMBER m_activeDarkest NOTIFY activeDarkestChanged)
    Q_PROPERTY(QColor cautionLight MEMBER m_cautionLight NOTIFY cautionLightChanged)
    Q_PROPERTY(QColor cautionNormal MEMBER m_cautionNormal NOTIFY cautionNormalChanged)
    Q_PROPERTY(QColor cautionDark MEMBER m_cautionDark NOTIFY cautionDarkChanged)
    Q_PROPERTY(QColor cautionDarkest MEMBER m_cautionDarkest NOTIFY cautionDarkestChanged)
    Q_PROPERTY(QColor greyWhite MEMBER m_greyWhite NOTIFY greyWhiteChanged)
    Q_PROPERTY(QColor greyLight MEMBER m_greyLight NOTIFY greyLightChanged)
    Q_PROPERTY(QColor greyMedium MEMBER m_greyMedium NOTIFY greyMediumChanged)
    Q_PROPERTY(QColor greyDark MEMBER m_greyDark NOTIFY greyDarkChanged)
    Q_PROPERTY(QColor greyDarkest MEMBER m_greyDarkest NOTIFY greyDarkestChanged)
    Q_PROPERTY(QColor greyBlack MEMBER m_greyBlack NOTIFY greyBlackChanged)
    Q_PROPERTY(QColor shadow MEMBER m_shadow NOTIFY shadowChanged)

public:
    enum ColorTheme {
        Light,
        Dark
    };

    BasePalette(ColorTheme p_colorTheme = Light, QObject *parent = nullptr);

    ColorTheme currentColorTheme();
    void setCurrentColorTheme(ColorTheme p_newColorTheme);

signals:
    void activeLightChanged();
    void activeNormalChanged();
    void activeDarkChanged();
    void activeDarkestChanged();
    void cautionLightChanged();
    void cautionNormalChanged();
    void cautionDarkChanged();
    void cautionDarkestChanged();
    void greyWhiteChanged();
    void greyLightChanged();
    void greyMediumChanged();
    void greyDarkChanged();
    void greyDarkestChanged();
    void greyBlackChanged();
    void shadowChanged();

private:
    ColorTheme m_currentColorTheme;

    void updateColors();
    void initThemeDark();
    void initThemeLight();

    QColor m_activeLight;
    QColor m_activeNormal;
    QColor m_activeDark;
    QColor m_activeDarkest;

    QColor m_cautionLight;
    QColor m_cautionNormal;
    QColor m_cautionDark;
    QColor m_cautionDarkest;

    QColor m_greyWhite;
    QColor m_greyLight;
    QColor m_greyMedium;
    QColor m_greyDark;
    QColor m_greyDarkest;
    QColor m_greyBlack;

    QColor m_shadow;
};

#endif // BASEPALETTE_H
