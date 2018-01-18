#ifndef LINEARROWINDICATOR_H
#define LINEARROWINDICATOR_H


#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QPainterPath>

class LineArrowIndicator : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER m_arrowColor NOTIFY colorChanged())
public:
    LineArrowIndicator(QQuickItem *parent = 0);

    void paint(QPainter *painter);

signals:
    void colorChanged();

private:
    QColor m_arrowColor;
};

#endif // LINEARROWINDICATOR_H
