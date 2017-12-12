#ifndef ACTIONABLESURFACE_H
#define ACTIONABLESURFACE_H

#include <QQuickPaintedItem>
#include <QPainter>

#include "gradientgroup.h"
#include "basicanimator.h"
#include "bordergroup.h"

class ActionableSurface : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(GradientGroup* gradient MEMBER m_gradient NOTIFY gradientChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor pressedColor READ pressedColor WRITE setPressedColor NOTIFY pressedColorChanged)
    Q_PROPERTY(QColor pressedBorderColor READ pressedBorderColor WRITE setPressedBorderColor NOTIFY pressedBorderColorChanged)
    Q_PROPERTY(bool pressed READ pressed WRITE setPressed NOTIFY pressedChanged)
    Q_PROPERTY(qreal radius MEMBER m_radius NOTIFY radiusChanged)
    Q_PROPERTY(BorderGroup* border MEMBER m_border NOTIFY borderChanged)
    Q_PROPERTY(bool hovered READ hovered WRITE setHovered NOTIFY hoveredChanged)

public:
    ActionableSurface(QQuickItem *parent = 0);

    QColor color() const;
    void setColor(const QColor p_color);

    QColor pressedColor() const;
    void setPressedColor(const QColor p_pressedColor);

    QColor pressedBorderColor() const;
    void setPressedBorderColor(const QColor p_pressedBorderColor);

    bool pressed() const;
    void setPressed(const bool p_pressed);

    bool hovered() const;
    void setHovered(const bool p_hovered);

    void paint(QPainter *painter);

signals:
    void colorChanged();
    void pressedColorChanged();
    void pressedBorderColorChanged();
    void radiusChanged();
    void borderChanged();
    void pressedChanged();
    void hoveredChanged();
    void gradientChanged();



public slots:
    void receiveAnimValue(QVariant p_newValue);
    void updateGradient();
    void handleMousePressEvent();
    void handleMouseHoverEvent();



protected:
    void hoverMoveEvent(QHoverEvent *event);

    void componentComplete();


private:
    void updateGradientPos(QPointF p_center);
    void initAnimationEffects();

    void playAnimation();
    void playReverseAnimation();

    void mousePress();
    void mouseRelease();

    void hoverEnter();
    void hoverExit();

    bool m_hovered;
    BasicAnimator m_hoverAnimation;
    QColor m_color;
    QColor m_pressedColor;
    QColor m_pressedBorderColor;
    qreal m_radius;
    qreal m_gradientIntensity;
    BorderGroup* m_border;
    bool m_pressed;
    bool m_drawPressed;
    GradientGroup *m_gradient;
};

#endif // ACTIONABLESURFACE_H
