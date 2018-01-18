#ifndef BUSYINDICATORARC_H
#define BUSYINDICATORARC_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QPainterPath>

class BusyIndicatorArc : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER m_arcColor NOTIFY colorChanged)
    Q_PROPERTY(int arcWidth MEMBER m_arcWidth NOTIFY arcWidthChanged)
    Q_PROPERTY(int arcLength MEMBER m_arcLength NOTIFY arcLengthChanged)
public:
    BusyIndicatorArc(QQuickItem *p_parent = 0);

    void paint(QPainter *p_painter);

signals:
    void colorChanged();
    void arcWidthChanged();
    void arcLengthChanged();

private:
    QColor m_arcColor;
    int m_arcWidth;
    int m_arcLength;
};

#endif // BUSYINDICATORARC_H
