#ifndef BASEPALETTE_H
#define BASEPALETTE_H

#include <QObject>
#include <QColor>


class BasePalette : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor primaryLight READ primaryLight CONSTANT)
    Q_PROPERTY(QColor primaryNormal READ primaryNormal CONSTANT)
    Q_PROPERTY(QColor primaryMid READ primaryMid CONSTANT)
    Q_PROPERTY(QColor primaryDark READ primaryDark CONSTANT)

    Q_PROPERTY(QColor dangerousLight READ dangerousLight CONSTANT)
    Q_PROPERTY(QColor dangerousNormal READ dangerousNormal CONSTANT)
    Q_PROPERTY(QColor dangerousMid READ dangerousMid CONSTANT)
    Q_PROPERTY(QColor dangerousDark READ dangerousDark CONSTANT)

    Q_PROPERTY(QColor greyWhite READ greyWhite CONSTANT)
    Q_PROPERTY(QColor greyLight READ greyLight CONSTANT)
    Q_PROPERTY(QColor greyMidLight READ greyMidLight CONSTANT)
    Q_PROPERTY(QColor greyMid READ greyMid CONSTANT)
    Q_PROPERTY(QColor greyMidDark READ greyMidDark CONSTANT)
    Q_PROPERTY(QColor greyDark READ greyDark CONSTANT)
    Q_PROPERTY(QColor greyBlack READ greyBlack CONSTANT)

    Q_PROPERTY(QColor textNormal READ textNormal CONSTANT)
    Q_PROPERTY(QColor textHover READ textHover CONSTANT)

    Q_PROPERTY(QColor shadow READ shadow CONSTANT)

public:

    enum ColorScheme {
        Dark,
        Light
    };

    BasePalette(ColorScheme p_colorScheme = Light, QObject *parent = nullptr);

    void setColorScheme(const ColorScheme &p_newScheme);

    QColor primaryLight() const;
    QColor primaryNormal() const;
    QColor primaryMid() const;
    QColor primaryDark() const;

    QColor dangerousLight() const;
    QColor dangerousNormal() const;
    QColor dangerousMid() const;
    QColor dangerousDark() const;

    QColor greyWhite() const;
    QColor greyLight() const;
    QColor greyMidLight() const;
    QColor greyMid() const;
    QColor greyMidDark() const;
    QColor greyDark() const;
    QColor greyBlack() const;
    QColor shadow() const;

    QColor textNormal() const;
    QColor textHover() const;

private:
    void initColors(const ColorScheme &p_colorScheme = Light);

    void initLightColors();
    void initDarkColors();

    const QColor m_primaryHue = QColor::fromRgb(51, 204, 153);
    const QColor m_dangerousHue = QColor::fromRgb(255, 51, 153);
    QColor m_greyHue;

    QColor m_primaryLight;
    QColor m_primaryMid;
    QColor m_primaryDark;

    QColor m_dangerousLight;
    QColor m_dangerousMid;
    QColor m_dangerousDark;

    QColor m_greyWhite;
    QColor m_greyLight;
    QColor m_greyMidLight;
    QColor m_greyMidDark;
    QColor m_greyDark;
    QColor m_greyBlack;

    QColor m_textNormal;
    QColor m_textHover;

    QColor m_shadow;
};

#endif // BASEPALETTE_H
