#ifndef BASEPALETTE_H
#define BASEPALETTE_H

#include <QObject>
#include <QColor>


class BasePalette : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool dark READ dark WRITE setDark NOTIFY darkChanged)

    Q_PROPERTY(QColor accentLight READ accentLight CONSTANT)
    Q_PROPERTY(QColor accent READ accent CONSTANT)
    Q_PROPERTY(QColor accentDark READ accentDark CONSTANT)

    Q_PROPERTY(QColor dangerousLight READ dangerousLight CONSTANT)
    Q_PROPERTY(QColor dangerous READ dangerous CONSTANT)
    Q_PROPERTY(QColor dangerousDark READ dangerousDark CONSTANT)

    Q_PROPERTY(QColor content READ content CONSTANT)
    Q_PROPERTY(QColor contentSecondary READ contentSecondary CONSTANT)
    Q_PROPERTY(QColor window READ window WRITE setWindow NOTIFY windowChanged)
    Q_PROPERTY(QColor sunken READ sunken CONSTANT)
    Q_PROPERTY(QColor sunkenDark READ sunkenDark CONSTANT)
    Q_PROPERTY(QColor raised READ raised CONSTANT)

    Q_PROPERTY(QColor shadow READ shadow CONSTANT)

public:
    BasePalette(QObject *parent = nullptr);

    bool dark() const;
    void setDark(const bool &p_isDark);

    QColor accentLight() const;
    QColor accent() const;
    QColor accentDark() const;

    QColor dangerousLight() const;
    QColor dangerous() const;
    QColor dangerousDark() const;

    QColor content() const;
    QColor contentSecondary() const;

    QColor window() const;
    void setWindow(const QColor &p_color);

    QColor sunken() const;
    QColor sunkenDark() const;
    QColor raised() const;
    QColor shadow() const;

signals:
    void darkChanged();
    void windowChanged();

private:
    const QColor M_ACCENT = QColor::fromRgb(51, 204, 153);
    const QColor M_DANGEROUS = QColor::fromRgb(255, 51, 153);
    const QColor M_GREYS_LIGHT = QColor::fromRgb(204, 200, 208);
    const QColor M_GREYS_DARK = QColor::fromRgb(77, 70, 83);


    void initColors();

    void updateGreys();
    void changeToDarkGreys();
    void changeToLightGreys();

    bool m_dark;

    QColor m_accentLight;
    QColor m_accent;
    QColor m_accentDark;

    QColor m_dangerousLight;
    QColor m_dangerous;
    QColor m_dangerousDark;

    QColor m_content;
    QColor m_contentSecondary;
    QColor m_window;
    QColor m_sunken;
    QColor m_sunkenDark;
    QColor m_raised;

    QColor m_shadow;
};

#endif // BASEPALETTE_H
