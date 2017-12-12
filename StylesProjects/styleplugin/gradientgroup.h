#ifndef GRADIENTGROUP_H
#define GRADIENTGROUP_H

#include <QObject>
#include <QRadialGradient>
#include "bordergroup.h"

class GradientGroup : public QObject
{
    Q_OBJECT
    Q_PROPERTY(BorderGroup* border READ border NOTIFY gradientChanged)
    Q_PROPERTY(QColor mainColor READ mainColor WRITE setMainColor NOTIFY gradientChanged)
    Q_PROPERTY(QColor secondaryColor READ secondaryColor WRITE setSecondaryColor NOTIFY gradientChanged)
public:
    explicit GradientGroup(QObject *parent = nullptr);

    QColor  mainColor() const;
    void setMainColor(const QColor p_mainColor);

    QColor secondaryColor() const;
    void setSecondaryColor(const QColor p_secondaryColor);

    BorderGroup* border() const;

    void setSize(const qreal p_size);

    void setCenter(const QPointF p_center);

    QRadialGradient* gradient() const;

signals:
    void gradientChanged();

public slots:

private:
    BorderGroup* m_border;
    QRadialGradient* m_gradient;
    QColor m_mainColor;
    QColor m_secondaryColor;
    QPointF m_center;
    qreal m_size;
};

#endif // GRADIENTGROUP_H
