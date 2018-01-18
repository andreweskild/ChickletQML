#include "styleplugin_plugin.h"
#include "styleplugin.h"
#include "checkboxindicator.h"
#include "interactivegradientitem.h"
#include "basepalette.h"
#include "dimensionsprovider.h"
#include "linearrowindicator.h"
#include "busyindicatorarc.h"
#include "delaybuttonprogressindicator.h"
#include "palette.h"

#include <qqml.h>

void StylepluginPlugin::registerTypes(const char *uri)
{
    // @uri styleplugin
    qmlRegisterUncreatableType<StylePlugin>(uri, 1, 0, "StylePlugin", "For Stuff");
    qmlRegisterType<Palette>(uri, 1, 0, "Palette");
    qmlRegisterType<PaletteAttached>();
    qmlRegisterType<DimensionsProvider>(uri, 1, 0, "DimensionsProvider");
    qmlRegisterType<BasePalette>(uri, 1, 0, "BasePalette");
    qmlRegisterType<CheckBoxIndicator>(uri, 1, 0, "CheckBoxIndicator");
    qmlRegisterType<LineArrowIndicator>(uri, 1, 0, "LineArrowIndicator");
    qmlRegisterType<BusyIndicatorArc>(uri, 1, 0, "BusyIndicatorArc");
    qmlRegisterType<InteractiveGradientItem>(uri, 1, 0, "InteractiveGradientItem");
    qmlRegisterType<DelayButtonProgressIndicator>(uri, 1, 0, "DelayButtonProgressIndicator");
}

