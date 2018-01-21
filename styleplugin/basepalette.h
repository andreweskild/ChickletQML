#ifndef BASEPALETTE_H
#define BASEPALETTE_H

#include <QObject>
#include <QColor>


class BasePalette : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool dark READ dark WRITE setDark NOTIFY darkChanged)

    Q_PROPERTY(QColor accentLight READ accentLight WRITE setAccentLight NOTIFY accentLightChanged)
    Q_PROPERTY(QColor accent READ accent WRITE setAccent NOTIFY accentChanged)
    Q_PROPERTY(QColor accentDark READ accentDark WRITE setAccentDark NOTIFY accentDarkChanged)

    Q_PROPERTY(QColor dangerousLight READ dangerousLight WRITE setDangerousLight NOTIFY dangerousLightChanged)
    Q_PROPERTY(QColor dangerous READ dangerous WRITE setDangerous NOTIFY dangerousChanged)
    Q_PROPERTY(QColor dangerousDark READ dangerousDark WRITE setDangerousDark NOTIFY dangerousDarkChanged)

    Q_PROPERTY(QColor content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(QColor contentSecondary READ contentSecondary WRITE setContentSecondary NOTIFY contentSecondaryChanged)
    Q_PROPERTY(QColor window READ window WRITE setWindow NOTIFY windowChanged)
    Q_PROPERTY(QColor sunken READ sunken WRITE setSunken NOTIFY sunkenChanged)
    Q_PROPERTY(QColor sunkenDark READ sunkenDark WRITE setSunkenDark NOTIFY sunkenDarkChanged)
    Q_PROPERTY(QColor raised READ raised WRITE setRaised NOTIFY raisedChanged)

    Q_PROPERTY(QColor shadow READ shadow WRITE setShadow NOTIFY shadowChanged)

public:
    BasePalette(QObject *parent = nullptr);

    bool dark() const;
    void setDark(const bool &p_isDark);

    QColor accentLight() const;
    void setAccentLight(const QColor &p_color);

    QColor accent() const;
    void setAccent(const QColor &p_color);

    QColor accentDark() const;
    void setAccentDark(const QColor &p_color);

    QColor dangerousLight() const;
    void setDangerousLight(const QColor &p_color);

    QColor dangerous() const;
    void setDangerous(const QColor &p_color);

    QColor dangerousDark() const;
    void setDangerousDark(const QColor &p_color);

    QColor content() const;
    void setContent(const QColor &p_color);

    QColor contentSecondary() const;
    void setContentSecondary(const QColor &p_color);

    QColor window() const;
    void setWindow(const QColor &p_color);

    QColor sunken() const;
    void setSunken(const QColor &p_color);

    QColor sunkenDark() const;
    void setSunkenDark(const QColor &p_color);

    QColor raised() const;
    void setRaised(const QColor &p_color);

    QColor shadow() const;
    void setShadow(const QColor &p_color);

signals:
    void darkChanged();

    void accentLightChanged();
    void accentChanged();
    void accentDarkChanged();

    void dangerousLightChanged();
    void dangerousChanged();
    void dangerousDarkChanged();

    void contentChanged();
    void contentSecondaryChanged();
    void windowChanged();
    void sunkenChanged();
    void sunkenDarkChanged();
    void raisedChanged();
    void shadowChanged();

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
