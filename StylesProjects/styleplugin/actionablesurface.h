#ifndef ACTIONABLESURFACE_H
#define ACTIONABLESURFACE_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QRadialGradient>
#include "basicanimator.h"

#include "bordergroup.h"

class ActionableSurface : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor mainColor READ mainColor WRITE setMainColor NOTIFY mainColorChanged)
    Q_PROPERTY(QColor gradientBorderColor READ gradientBorderColor WRITE setGradientBorderColor NOTIFY gradientBorderColorChanged)
    Q_PROPERTY(QColor mainGradientColor READ mainGradientColor WRITE setMainGradientColor NOTIFY mainGradientColorChanged)
    Q_PROPERTY(QColor secondaryGradientColor READ secondaryGradientColor WRITE setSecondaryGradientColor NOTIFY secondaryGradientColorChanged)
    Q_PROPERTY(QColor pressedColor READ pressedColor WRITE setPressedColor NOTIFY pressedColorChanged)
    Q_PROPERTY(QColor pressedBorderColor READ pressedBorderColor WRITE setPressedBorderColor NOTIFY pressedBorderColorChanged)
    Q_PROPERTY(bool isPressed READ isPressed WRITE setIsPressed NOTIFY isPressedChanged)
    Q_PROPERTY(qreal radius MEMBER m_radius NOTIFY radiusChanged)
    Q_PROPERTY(BorderGroup* border MEMBER m_border NOTIFY borderChanged)

public:
    ActionableSurface(QQuickItem *parent = 0);

    QColor mainColor() const;
    void setMainColor(const QColor p_mainColor);

    QColor mainGradientColor() const;
    void setMainGradientColor(const QColor p_mainGradientColor);

    QColor secondaryGradientColor() const;
    void setSecondaryGradientColor(const QColor p_secondaryGradientColor);

    QColor gradientBorderColor() const;
    void setGradientBorderColor(const QColor p_gradientBorderColor);

    QColor pressedColor() const;
    void setPressedColor(const QColor p_pressedColor);

    QColor pressedBorderColor() const;
    void setPressedBorderColor(const QColor p_pressedBorderColor);

    bool isPressed() const;
    void setIsPressed(const bool p_isPressed);

    void paint(QPainter *painter);

signals:
    void mainColorChanged();
    void gradientBorderColorChanged();
    void mainGradientColorChanged();
    void secondaryGradientColorChanged();
    void pressedColorChanged();
    void pressedBorderColorChanged();
    void radiusChanged();
    void borderChanged();
    void isPressedChanged();

public slots:
    void receiveAnimValue(QVariant p_newValue);
    void updateGradientSize();
    void handleMouseEvent();


protected:
    void hoverEnterEvent(QHoverEvent *event);
    void hoverLeaveEvent(QHoverEvent *event);
    void hoverMoveEvent(QHoverEvent *event);


private:
    void initGradientEffect();
    void updateGradientColors(QColor p_main, QColor p_secondary);
    void updateGradientPos(QPointF p_center);
    void initAnimationEffects();

    void playAnimation();
    void playReverseAnimation();

    void mousePress();
    void mouseRelease();


    BasicAnimator m_hoverAnimation;
    QRadialGradient* m_surfaceGradient;
    QColor m_mainColor;
    QColor m_mainGradientColor;
    QColor m_secondaryGradientColor;
    QColor m_gradientBorderColor;
    QColor m_pressedColor;
    QColor m_pressedBorderColor;
    qreal m_radius;
    qreal m_gradientIntensity;
    BorderGroup* m_border;
    bool m_pressed;
};

#endif // ACTIONABLESURFACE_H
