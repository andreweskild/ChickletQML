#ifndef PALETTE_H
#define PALETTE_H

#include <QObject>
#include <QColor>
#include <QQmlEngine>

class PaletteAttached : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor primaryNormal READ primaryNormal CONSTANT)
public:
    PaletteAttached(QObject *p_parent);

    QColor primaryNormal() const;

private:
    QColor m_primaryNormal = Qt::red;
};

class Palette : public QObject
{
    Q_OBJECT
public:
    Palette(QObject *parent = nullptr);

    static PaletteAttached *qmlAttachedProperties(QObject *p_parent);

};

QML_DECLARE_TYPEINFO(Palette, QML_HAS_ATTACHED_PROPERTIES)
#endif // PALETTE_H
