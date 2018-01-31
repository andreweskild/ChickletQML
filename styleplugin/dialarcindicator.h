#ifndef DIALARCINDICATOR_H
#define DIALARCINDICATOR_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QPainterPath>


class DialArcIndicator : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color MEMBER m_arcColor NOTIFY colorChanged)
    Q_PROPERTY(int arcWidth MEMBER m_arcWidth NOTIFY arcWidthChanged)
    Q_PROPERTY(qreal progress MEMBER m_progress NOTIFY progressChanged)
    Q_PROPERTY(QPointF endPoint MEMBER m_endPoint NOTIFY endPointChanged)
public:
    DialArcIndicator(QQuickItem *p_parent = 0);
    void paint(QPainter *p_painter);
signals:
    void colorChanged();
    void arcWidthChanged();
    void progressChanged();
    void endPointChanged();

public slots:
    void updateArc();

private:
    QPointF m_endPoint;
    QPainterPath m_path;
    QColor m_arcColor;
    int m_arcWidth;
    qreal m_progress;
};

#endif // DIALARCINDICATOR_H
