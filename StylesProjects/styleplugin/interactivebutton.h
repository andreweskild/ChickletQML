#ifndef INTERACTIVEBUTTON_H
#define INTERACTIVEBUTTON_H

#include "interactivegradientitem.h"

class InteractiveButton : public InteractiveGradientItem
{
public:
    InteractiveButton(QQuickItem *p_parent = 0);

    QNanoQuickItemPainter *createItemPainter() const;
};

#endif // INTERACTIVEBUTTON_H
