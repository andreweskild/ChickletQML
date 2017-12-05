#ifndef ACTIONABLESURFACE_H
#define ACTIONABLESURFACE_H

#include <QQuickPaintedItem>
#include <QPainter>
#include "bordergroup.h"

class ActionableSurface : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor mainColor READ mainColor WRITE setMainColor NOTIFY mainColorChanged)
    Q_PROPERTY(QColor secondaryColor READ secondaryColor WRITE setSecondaryColor NOTIFY secondaryColorChanged)
    Q_PROPERTY(QColor mainActiveColor READ mainActiveColor WRITE setMainActiveColor NOTIFY mainActiveColorChanged)
    Q_PROPERTY(QColor secondaryActiveColor READ secondaryActiveColor WRITE setSecondaryActiveColor NOTIFY secondaryActiveColorChanged)
    Q_PROPERTY(QColor activeBorderColor READ activeBorderColor WRITE setActiveBorderColor NOTIFY activeBorderColorChanged)
    Q_PROPERTY(qreal radius MEMBER m_radius NOTIFY radiusChanged)
    Q_PROPERTY(BorderGroup* border MEMBER m_border NOTIFY borderChanged)

public:
    ActionableSurface(QQuickItem *parent = 0);

    QColor mainColor() const;
    void setMainColor(const QColor p_mainColor);

    QColor secondaryColor() const;
    void setSecondaryColor(const QColor p_secondaryColor);


    QColor mainActiveColor() const;
    void setMainActiveColor(const QColor p_mainActiveColor);

    QColor secondaryActiveColor() const;
    void setSecondaryActiveColor(const QColor p_secondaryActiveColor);

    QColor activeBorderColor() const;
    void setActiveBorderColor(const QColor p_activeBorderColor);

    void paint(QPainter *painter);

signals:
    void mainColorChanged();
    void secondaryColorChanged();
    void mainActiveColorChanged();
    void secondaryActiveColorChanged();
    void activeBorderColorChanged();
    void radiusChanged();
    void borderChanged();

public slots:
    void widgetWidthChanged();


protected:
    void hoverEnterEvent(QHoverEvent *event);
    void hoverLeaveEvent(QHoverEvent *event);
    void hoverMoveEvent(QHoverEvent *event);

private:
    void initGradientEffect(QPointF p_center);

    QRadialGradient* m_surfaceGradient;
    QColor m_mainColor;
    QColor m_secondaryColor;
    QColor m_mainActiveColor;
    QColor m_secondaryActiveColor;
    QColor m_activeBorderColor;
    qreal m_radius;
    BorderGroup* m_border;
    bool m_hovered;
};

#endif // ACTIONABLESURFACE_H
