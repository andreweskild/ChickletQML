#ifndef INTERACTIVEGRADIENTITEM_H
#define INTERACTIVEGRADIENTITEM_H

#include "qnanoquickitem.h"
#include "qnanoquickitempainter.h"
#include "bordergroup.h"
#include "qnanoradialgradient.h"

class InteractiveGradientPainter : public QNanoQuickItemPainter
{
public:
    InteractiveGradientPainter();

    void paint(QNanoPainter *p);

    void synchronize(QNanoQuickItem *p_item);

private:
    QColor m_borderColor;
    qreal m_borderWidth;
    QNanoRadialGradient m_gradient;
    QPointF m_mousePos;
};


class InteractiveGradientItem : public QNanoQuickItem
{
    Q_OBJECT

    Q_PROPERTY(BorderGroup *border READ border NOTIFY borderChanged)
    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor secondaryColor READ secondaryColor WRITE setSecondaryColor NOTIFY secondaryColorChanged)
public:
    InteractiveGradientItem(QQuickItem *p_parent = 0);

    BorderGroup *border();
    
    QColor primaryColor() const;
    void setPrimaryColor(const QColor p_primaryColor);

    QColor secondaryColor() const;
    void setSecondaryColor(const QColor p_secondaryColor);

    QPointF mousePosition() const;
    void updateMousePosition(const QPointF p_mousePos);

    QNanoQuickItemPainter *createItemPainter() const;

signals:
    void primaryColorChanged();
    void secondaryColorChanged();
    void borderChanged();

protected:
    void hoverMoveEvent(QHoverEvent *p_event);

private:
    BorderGroup *m_border = nullptr;
    QColor m_primaryColor;
    QColor m_secondaryColor;
    QPointF m_mousePos;

};

#endif // INTERACTIVEGRADIENTITEM_H
