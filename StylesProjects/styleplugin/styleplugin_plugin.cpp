#include "styleplugin_plugin.h"
#include "styleplugin.h"
#include "actionablesurface.h"
#include "checkboxindicator.h"
#include "gradientsurface.h"
#include "interactivegradientitem.h"

#include <qqml.h>

void StylepluginPlugin::registerTypes(const char *uri)
{
    // @uri styleplugin
    qmlRegisterUncreatableType<StylePlugin>(uri, 1, 0, "StylePlugin", "For Stuff");
    qmlRegisterType<ActionableSurface>(uri, 1, 0, "ActionableSurface");
    qmlRegisterType<BorderGroup>(uri, 1, 0, "BorderGroup");
    qmlRegisterType<GradientGroup>(uri, 1, 0, "GradientGroup");
    qmlRegisterType<CheckBoxIndicator>(uri, 1, 0, "CheckBoxIndicator");
    qmlRegisterType<GradientSurface>(uri, 1, 0, "GradientSurface");
    qmlRegisterType<InteractiveGradientItem>(uri, 1, 0, "InteractiveGradient");
}

