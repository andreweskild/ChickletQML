#include "styleplugin_plugin.h"
#include "styleplugin.h"
#include "actionablesurface.h"
#include "checkboxindicator.h"

#include <qqml.h>

void StylepluginPlugin::registerTypes(const char *uri)
{
    // @uri styleplugin
    qmlRegisterUncreatableType<StylePlugin>(uri, 1, 0, "StylePlugin", "For Stuff");
    qmlRegisterType<ActionableSurface>(uri, 1, 0, "ActionableSurface");
    qmlRegisterType<BorderGroup>(uri, 1, 0, "BorderGroup");
    qmlRegisterType<CheckBoxIndicator>(uri, 1, 0, "CheckBoxIndicator");
}

