#ifndef INTERACTIVEROUNDBUTTON_H
#define INTERACTIVEROUNDBUTTON_H

#include "interactivegradientitem.h"

class InteractiveRoundButton : public InteractiveGradientItem
{
public:
    InteractiveRoundButton(QQuickItem *p_parent = 0);

    QNanoQuickItemPainter *createItemPainter() const;
};

#endif // INTERACTIVEROUNDBUTTON_H
