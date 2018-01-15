import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.MenuSeparator {
    id: control

    implicitWidth: parent.width
    implicitHeight: topPadding + bottomPadding + contentItem.implicitHeight

    topPadding: 2
    bottomPadding: 2

    contentItem: Rectangle {
        implicitHeight: 2
        width: control.width
        color: StylePlugin.palette.greyMidLight
    }
}
