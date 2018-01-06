import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.MenuSeparator {
    id: control

    implicitWidth: parent.width
    implicitHeight: topPadding + bottomPadding + contentItem.implicitHeight

    topPadding: 4
    bottomPadding: 4

    contentItem: Rectangle {
        implicitHeight: 1
        width: control.width
        color: StylePlugin.palette.greyMid
    }
}
