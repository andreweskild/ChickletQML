#include "styleplugin_plugin.h"
#include "styleplugin.h"
#include "checkboxindicator.h"
#include "interactivegradientitem.h"
#include "basepalette.h"
#include "dimensionsprovider.h"
#include "rectangleitem.h"
#include "linearrowindicator.h"
#include "interactiveroundbutton.h"
#include "interactivebutton.h"
#include "interactivemenuitem.h"
#include "busyindicatorarc.h"

#include <qqml.h>

void StylepluginPlugin::registerTypes(const char *uri)
{
    // @uri styleplugin
    qmlRegisterUncreatableType<StylePlugin>(uri, 1, 0, "StylePlugin", "For Stuff");
    qmlRegisterType<DimensionsProvider>(uri, 1, 0, "DimensionsProvider");
    qmlRegisterType<BasePalette>(uri, 1, 0, "BasePalette");
    qmlRegisterType<CheckBoxIndicator>(uri, 1, 0, "CheckBoxIndicator");
    qmlRegisterType<LineArrowIndicator>(uri, 1, 0, "LineArrowIndicator");
    qmlRegisterType<BusyIndicatorArc>(uri, 1, 0, "BusyIndicatorArc");
    qmlRegisterType<InteractiveRoundButton>(uri, 1, 0, "InteractiveRoundButton");
    qmlRegisterType<InteractiveButton>(uri, 1, 0, "InteractiveButton");
    qmlRegisterType<InteractiveMenuItem>(uri, 1, 0, "InteractiveMenuItem");
    qmlRegisterType<RectangleItem>(uri, 1, 0, "RectangleItem");
}

