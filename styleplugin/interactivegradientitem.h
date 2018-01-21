#ifndef INTERACTIVEGRADIENTITEM_H
#define INTERACTIVEGRADIENTITEM_H

#include "qnanoquickitem.h"
#include "qnanoquickitempainter.h"
#include "qnanoradialgradient.h"
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include "basepalette.h"


class InteractiveGradientItem : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor secondaryColor READ secondaryColor WRITE setSecondaryColor NOTIFY secondaryColorChanged)
    Q_PROPERTY(Shape shape READ shape WRITE setShape NOTIFY shapeChanged)

public:
    enum Shape {
        Rect,
        RoundedRect,
        Circle
    };
    Q_ENUM(Shape)

    InteractiveGradientItem(QQuickItem *p_parent = 0);
    
    QColor primaryColor() const;
    void setPrimaryColor(const QColor &p_primaryColor);

    QColor secondaryColor() const;
    void setSecondaryColor(const QColor &p_secondaryColor);

    Shape shape() const;
    void setShape(const Shape &p_shape);


    QPointF mousePosition() const;
    void updateMousePosition(const QPointF &p_mousePos);

    QNanoQuickItemPainter *createItemPainter() const;


signals:
    void primaryColorChanged();
    void secondaryColorChanged();
    void shapeChanged();

protected:
    void hoverMoveEvent(QHoverEvent *p_event);



private:

    QPointF m_mousePos;

    QColor m_primaryColor;
    QColor m_secondaryColor;

    Shape m_shape;


};

class InteractiveGradientPainter : public QNanoQuickItemPainter
{
public:

    InteractiveGradientPainter(const InteractiveGradientItem::Shape &p_shape = InteractiveGradientItem::RoundedRect);

    void paint(QNanoPainter *p);

    void synchronize(QNanoQuickItem *p_item);

private:
    QNanoRadialGradient m_gradient;

    QNanoColor m_primaryColor;
    QNanoColor m_secondaryColor;
    QPointF m_mousePos;


    InteractiveGradientItem::Shape m_shape;

    const int M_RADIUS = 4;


};

#endif // INTERACTIVEGRADIENTITEM_H
