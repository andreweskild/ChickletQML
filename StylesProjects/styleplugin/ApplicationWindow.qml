import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.ApplicationWindow {
    id: window

    color: StylePlugin.palette.greyMidLight

    overlay.modal: Rectangle {
        color: window.color
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }

    overlay.modeless: Rectangle {
        color: window.color
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }
}
