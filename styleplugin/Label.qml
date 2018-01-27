import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.Label {
    id: control

    color: enabled ? ColorPalette.content : ColorPalette.sunken
    linkColor: ColorPalette.accent
}
