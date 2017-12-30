#ifndef RECTANGLEITEM_H
#define RECTANGLEITEM_H

#include "qnanoquickitem.h"
#include "qnanoquickitempainter.h"
#include "dimensionsprovider.h"
#include "basepalette.h"
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>


class RectanglePainter : public QNanoQuickItemPainter
{
public:
    RectanglePainter();

    void paint(QNanoPainter *p);

    void synchronize(QNanoQuickItem *p_item);

private:
    DimensionsProvider *m_dimensions;
    QColor m_primaryColor;
    QColor m_secondaryColor;
    QNanoColor m_borderColor;
    QNanoRadialGradient m_gradient;
    QPointF m_mousePos;

};

class RectangleItem : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(bool hovered MEMBER m_hovered NOTIFY hoveredChanged)
    Q_PROPERTY(bool pressed MEMBER m_pressed NOTIFY pressedChanged)
public:
    RectangleItem(QQuickItem *p_parent = 0);

    QColor borderColor() const;

    QColor primaryColor() const;

    QNanoQuickItemPainter *createItemPainter() const;

public slots:
    void setPrimaryColor(const QColor &p_primaryColor);
    void setBorderColor(const QColor &p_borderColor);

    void handleMousePress();
    void handleHover();

signals:
    void primaryColorChanged();
    void secondaryColorChanged();
    void borderColorChanged();
    void pressedChanged();
    void hoveredChanged();

    void pressed();
    void releasedNormal();
    void releasedHovered();

    void hoverEnter();
    void hoverLeave();


private:
    enum State {
        Normal,
        Hovered,
        Pressed
    };

    BasePalette *m_palette;

    QColor m_primaryColor;
    QColor m_borderColor;

    bool m_pressed;
    bool m_hovered;

    const QEasingCurve ANIM_EASING = QEasingCurve::OutSine;
    const int ANIM_DURATION = 100;

    QPropertyAnimation *m_borderAnimation;

    void initAnimations();
    void handleAnimation(State p_state);
};

#endif // RECTANGLEITEM_H
