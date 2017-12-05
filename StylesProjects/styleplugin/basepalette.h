#ifndef BASEPALETTE_H
#define BASEPALETTE_H

#include <QObject>
#include <QColor>

class BasePalette : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor activeMain READ activeMain)
    Q_PROPERTY(QColor activeHighlight READ activeHighlight)
    Q_PROPERTY(QColor activeDark READ activeDark)
    Q_PROPERTY(QColor activeDarkest READ activeDarkest)
    Q_PROPERTY(QColor dangerMain READ dangerMain)
    Q_PROPERTY(QColor dangerHighlight READ dangerHighlight)
    Q_PROPERTY(QColor dangerDark READ dangerDark)
    Q_PROPERTY(QColor dangerDarkest READ dangerDarkest)
    Q_PROPERTY(QColor disabledMain READ disabledMain)
    Q_PROPERTY(QColor disabledDark READ disabledDark)
    Q_PROPERTY(QColor actionableMain READ actionableMain)
    Q_PROPERTY(QColor actionableDark READ actionableDark)
    Q_PROPERTY(QColor actionableDarkest READ actionableDarkest)
    Q_PROPERTY(QColor structureBase READ structureBase)
    Q_PROPERTY(QColor structureMidGround READ structureMidGround)
    Q_PROPERTY(QColor structureTitlebar READ structureTitlebar)
    Q_PROPERTY(QColor structureBorder READ structureBorder)
    Q_PROPERTY(QColor textLight READ textLight)
    Q_PROPERTY(QColor textDark READ textDark)
    Q_PROPERTY(QColor shadow READ shadow)

public:
    enum ColorTheme {
        Light,
        Dark
    };

    BasePalette(ColorTheme p_colorTheme = Light, QObject *parent = nullptr);

    ColorTheme currentColorTheme();
    void setCurrentColorTheme(ColorTheme p_newColorTheme);

    QColor activeMain() const;
    QColor activeHighlight() const;
    QColor activeDark() const;
    QColor activeDarkest() const;
    QColor dangerMain() const;
    QColor dangerHighlight() const;
    QColor dangerDark() const;
    QColor dangerDarkest() const;
    QColor disabledMain() const;
    QColor disabledDark() const;
    QColor actionableMain() const;
    QColor actionableDark() const;
    QColor actionableDarkest() const;
    QColor structureBase() const;
    QColor structureMidGround() const;
    QColor structureTitlebar() const;
    QColor structureBorder() const;
    QColor textLight() const;
    QColor textDark() const;
    QColor shadow() const;

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
    QColor m_structureTitlebar;
    QColor m_structureBorder;

    QColor m_textLight;
    QColor m_textDark;

    QColor m_shadow;
};

#endif // BASEPALETTE_H
