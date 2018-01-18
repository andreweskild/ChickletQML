#ifndef CHECKBOXINDICATOR_H
#define CHECKBOXINDICATOR_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QPainterPath>

class CheckBoxIndicator : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER m_checkColor NOTIFY colorChanged())
    Q_PROPERTY(qreal lineWidth MEMBER m_checkWidth)
    Q_PROPERTY(qreal dashOffset READ dashOffset WRITE setDashOffset NOTIFY dashOffsetChanged)
public:
    CheckBoxIndicator(QQuickItem *parent = 0);

    void paint(QPainter *painter);

    qreal dashOffset() const;

    void setDashOffset(qreal &p_dashOffset);

signals:
    void colorChanged();
    void dashOffsetChanged();

private:
    qreal m_checkWidth;
    QColor m_checkColor;
    qreal m_dashOffset;
};

#endif // CHECKBOXINDICATOR_H
