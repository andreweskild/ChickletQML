#ifndef STYLEPLUGIN_H
#define STYLEPLUGIN_H

#include <QObject>
#include <QtQml>
#include <QColor>
#include "basepalette.h"
#include "dimensionsprovider.h"

class StylePlugin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(BasePalette* palette READ palette)
    Q_PROPERTY(DimensionsProvider* dimensions READ dimensions)
    Q_DISABLE_COPY(StylePlugin)

public:
    explicit StylePlugin(QObject *parent = nullptr);
    ~StylePlugin();

    static StylePlugin *qmlAttachedProperties(QObject *object);

    BasePalette* palette() const;
    DimensionsProvider* dimensions() const;

signals:

private:
    BasePalette* m_basePalette;
    DimensionsProvider* m_dimensions;
};

QML_DECLARE_TYPEINFO(StylePlugin, QML_HAS_ATTACHED_PROPERTIES)

#endif // STYLEPLUGIN_H
