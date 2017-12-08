#ifndef BASEPALETTE_H
#define BASEPALETTE_H

#include <QObject>
#include <QColor>

class BasePalette : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor activeMain MEMBER m_activeMain NOTIFY activeMainChanged)
    Q_PROPERTY(QColor activeHighlight MEMBER m_activeHighlight NOTIFY activeHighlightChanged)
    Q_PROPERTY(QColor activeDark MEMBER m_activeDark NOTIFY activeDarkChanged)
    Q_PROPERTY(QColor activeDarkest MEMBER m_activeDarkest NOTIFY activeDarkestChanged)
    Q_PROPERTY(QColor dangerMain MEMBER m_dangerMain NOTIFY dangerMainChanged)
    Q_PROPERTY(QColor dangerHighlight MEMBER m_dangerHighlight NOTIFY dangerHighlightChanged)
    Q_PROPERTY(QColor dangerDark MEMBER m_dangerDark NOTIFY dangerDarkChanged)
    Q_PROPERTY(QColor dangerDarkest MEMBER m_dangerDarkest NOTIFY dangerDarkestChanged)
    Q_PROPERTY(QColor disabledMain MEMBER m_disabledMain NOTIFY disabledMainChanged)
    Q_PROPERTY(QColor disabledDark MEMBER m_disabledDark NOTIFY disabledDarkChanged)
    Q_PROPERTY(QColor actionableMain MEMBER m_actionableMain NOTIFY actionableMainChanged)
    Q_PROPERTY(QColor actionableDark MEMBER m_actionableDark NOTIFY actionableDarkChanged)
    Q_PROPERTY(QColor actionableDarkest MEMBER m_actionableDarkest NOTIFY actionableDarkestChanged)
    Q_PROPERTY(QColor structureBase MEMBER m_structureBase NOTIFY structureBaseChanged)
    Q_PROPERTY(QColor structureMidGround MEMBER m_structureMidGround NOTIFY structureMidGroundChanged)
    Q_PROPERTY(QColor structureLowGround MEMBER m_structureLowGround NOTIFY structureLowGroundChanged)
    Q_PROPERTY(QColor structureBorder MEMBER m_structureBorder NOTIFY structureBorderChanged)
    Q_PROPERTY(QColor textLight MEMBER m_textLight NOTIFY textLightChanged)
    Q_PROPERTY(QColor textDark MEMBER m_textDark NOTIFY textDarkChanged)
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
    void activeMainChanged();
    void activeHighlightChanged();
    void activeDarkChanged();
    void activeDarkestChanged();
    void dangerMainChanged();
    void dangerHighlightChanged();
    void dangerDarkChanged();
    void dangerDarkestChanged();
    void disabledMainChanged();
    void disabledDarkChanged();
    void actionableMainChanged();
    void actionableDarkChanged();
    void actionableDarkestChanged();
    void structureBaseChanged();
    void structureMidGroundChanged();
    void structureLowGroundChanged();
    void structureBorderChanged();
    void textLightChanged();
    void textDarkChanged();
    void shadowChanged();

private:
    ColorTheme m_currentColorTheme;

    void updateColors();
    void initThemeDark();
    void initThemeLight();

    QColor m_activeMain;
    QColor m_activeHighlight;
    QColor m_activeDark;
    QColor m_activeDarkest;

    QColor m_dangerMain;
    QColor m_dangerHighlight;
    QColor m_dangerDark;
    QColor m_dangerDarkest;

    QColor m_disabledMain;
    QColor m_disabledDark;

    QColor m_actionableMain;
    QColor m_actionableDark;
    QColor m_actionableDarkest;

    QColor m_structureBase;
    QColor m_structureMidGround;
    QColor m_structureLowGround;
    QColor m_structureBorder;

    QColor m_textLight;
    QColor m_textDark;

    QColor m_shadow;
};

#endif // BASEPALETTE_H
