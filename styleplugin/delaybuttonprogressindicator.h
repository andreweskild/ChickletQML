#ifndef DELAYBUTTONPROGRESSINDICATOR_H
#define DELAYBUTTONPROGRESSINDICATOR_H


#include "qnanoquickitem.h"
#include "qnanoquickitempainter.h"
#include "qnanoradialgradient.h"
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include "basepalette.h"


class DelayButtonProgressIndicator : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(qreal progress MEMBER m_progress NOTIFY progressChanged)
public:
    DelayButtonProgressIndicator(QQuickItem *p_parent = 0);

    QColor color() const;

    void setColor(const QColor &p_color);

    qreal progressWidth() const;

    QNanoQuickItemPainter *createItemPainter() const;

signals:
    void colorChanged();
    void progressChanged();

private:
    QColor m_color;
    qreal m_progress;
};

class DelayButtonProgressPainter : public QNanoQuickItemPainter
{
public:

    DelayButtonProgressPainter();

    void paint(QNanoPainter *p);

    void synchronize(QNanoQuickItem *p_item);

private:

    QNanoColor m_color;
    qreal m_progress;
    const int M_RADIUS = 4;


};

#endif // DELAYBUTTONPROGRESSINDICATOR_H
