#ifndef BORDERGROUP_H
#define BORDERGROUP_H

#include <QObject>
#include <QColor>
#include <QtQml>

class BorderGroup : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int width MEMBER m_width NOTIFY widthChanged)
    Q_PROPERTY(QColor color MEMBER m_color NOTIFY colorChanged)
public:
    explicit BorderGroup(QObject *parent = nullptr);

    static BorderGroup *qmlAttachedProperties(QObject *object);

    int width()const;
    QColor color() const;

signals:
    void widthChanged();
    void colorChanged();

public slots:

private:
    int m_width;
    QColor m_color;
};

QML_DECLARE_TYPEINFO(BorderGroup, QML_HAS_ATTACHED_PROPERTIES)

#endif // BORDERGROUP_H
