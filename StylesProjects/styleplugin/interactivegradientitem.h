#ifndef INTERACTIVEGRADIENTITEM_H
#define INTERACTIVEGRADIENTITEM_H

#include "qnanoquickitem.h"
#include "qnanoquickitempainter.h"
#include "qnanoradialgradient.h"
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include "basepalette.h"
#include "dimensionsprovider.h"


class InteractiveGradientItem : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor secondaryColor READ secondaryColor WRITE setSecondaryColor NOTIFY secondaryColorChanged)
    Q_PROPERTY(bool pressed MEMBER m_pressed NOTIFY pressedChanged)
    Q_PROPERTY(bool hovered MEMBER m_hovered NOTIFY hoveredChanged)


public:
    InteractiveGradientItem(QQuickItem *p_parent = 0);
    
    QColor primaryColor() const;

    QColor secondaryColor() const;



    QPointF mousePosition() const;
    void updateMousePosition(const QPointF &p_mousePos);

    QNanoQuickItemPainter *createItemPainter() const;

public slots:
    void setPrimaryColor(const QColor &p_primaryColor);
    void setSecondaryColor(const QColor &p_secondaryColor);

    void handleMousePress();
    void handleHover();

signals:
    void primaryColorChanged();
    void secondaryColorChanged();
    void pressedChanged();
    void hoveredChanged();

    void pressed();
    void releasedNormal();
    void releasedHovered();

    void hoverEnter();
    void hoverLeave();

protected:
    void hoverMoveEvent(QHoverEvent *p_event);

    BasePalette *m_palette;

    QColor m_primaryColor;
    QColor m_secondaryColor;

private:
    enum State {
        Normal,
        Hovered,
        Pressed
    };

    QPointF m_mousePos;
    bool m_pressed;
    bool m_hovered;

    const QEasingCurve ANIM_EASING = QEasingCurve::InOutSine;
    const int ANIM_DURATION = 150;

    QParallelAnimationGroup *m_group;
    QPropertyAnimation *m_primaryAnimation;
    QPropertyAnimation *m_secondaryAnimation;

    void initAnimations();
    void handleAnimation(State p_state);



};

class InteractiveGradientPainter : public QNanoQuickItemPainter
{
public:
    enum Shape {
        Rect,
        RoundedRect,
        Circle
    };

    InteractiveGradientPainter(const Shape &p_shape = Rect);

    ~InteractiveGradientPainter();

    void paint(QNanoPainter *p);

    void synchronize(QNanoQuickItem *p_item);

private:
    DimensionsProvider *m_dimensions;
    QNanoRadialGradient m_gradient;

    QNanoColor m_primaryColor;
    QNanoColor m_secondaryColor;
    QPointF m_mousePos;

    int m_borderWidth;
    qreal m_radius;

    Shape m_shape;

};

#endif // INTERACTIVEGRADIENTITEM_H
