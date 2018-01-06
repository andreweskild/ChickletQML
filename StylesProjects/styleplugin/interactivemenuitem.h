#ifndef INTERACTIVEMENUITEM_H
#define INTERACTIVEMENUITEM_H

#include "interactivegradientitem.h"

class InteractiveMenuItem : public InteractiveGradientItem
{
public:
    InteractiveMenuItem(QQuickItem *p_parent = 0);

    QNanoQuickItemPainter *createItemPainter() const;
};

#endif // INTERACTIVEMENUITEM_H
