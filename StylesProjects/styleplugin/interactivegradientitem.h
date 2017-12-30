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
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(bool pressed MEMBER m_pressed NOTIFY pressedChanged)
    Q_PROPERTY(bool hovered MEMBER m_hovered NOTIFY hoveredChanged)
    Q_PROPERTY(GeometryMode geometryMode MEMBER m_geometryMode NOTIFY geometryModeChanged)


public:
    enum GeometryMode {
        Rect,
        RoundedRect,
        Circle
    };
    Q_ENUM(GeometryMode)

    InteractiveGradientItem(QQuickItem *p_parent = 0);

    QColor borderColor() const;
    
    QColor primaryColor() const;

    QColor secondaryColor() const;



    QPointF mousePosition() const;
    void updateMousePosition(const QPointF &p_mousePos);

    QNanoQuickItemPainter *createItemPainter() const;

public slots:
    void setPrimaryColor(const QColor &p_primaryColor);
    void setSecondaryColor(const QColor &p_secondaryColor);
    void setBorderColor(const QColor &p_borderColor);

    void handleMousePress();
    void handleHover();

signals:
    void primaryColorChanged();
    void secondaryColorChanged();
    void borderColorChanged();
    void pressedChanged();
    void hoveredChanged();
    void geometryModeChanged();

    void pressed();
    void releasedNormal();
    void releasedHovered();

    void hoverEnter();
    void hoverLeave();

protected:
    void hoverMoveEvent(QHoverEvent *p_event);

private:
    enum State {
        Normal,
        Hovered,
        Pressed
    };

    BasePalette *m_palette;

    QColor m_primaryColor;
    QColor m_secondaryColor;
    QColor m_borderColor;

    GeometryMode m_geometryMode = RoundedRect;

    QPointF m_mousePos;
    bool m_pressed;
    bool m_hovered;

    const QEasingCurve ANIM_EASING = QEasingCurve::OutSine;
    const int ANIM_DURATION = 100;

    QParallelAnimationGroup *m_group;
    QPropertyAnimation *m_primaryAnimation;
    QPropertyAnimation *m_secondaryAnimation;
    QPropertyAnimation *m_borderAnimation;

    void initAnimations();
    void handleAnimation(State p_state);



};

class InteractiveGradientPainter : public QNanoQuickItemPainter
{
public:
    InteractiveGradientPainter();

    void paint(QNanoPainter *p);

    void synchronize(QNanoQuickItem *p_item);

private:
    DimensionsProvider *m_dimensions;
    QColor m_primaryColor;
    QColor m_secondaryColor;
    QNanoColor m_borderColor;
    QNanoRadialGradient m_gradient;
    QPointF m_mousePos;
    InteractiveGradientItem::GeometryMode m_geometryMode;
    qreal m_radius;

};

#endif // INTERACTIVEGRADIENTITEM_H
