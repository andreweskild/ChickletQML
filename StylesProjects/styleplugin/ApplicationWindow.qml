import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.ApplicationWindow {
    id: window

    color: Theme.window

    overlay.modal: Rectangle {
        color: window.color
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }

    overlay.modeless: Rectangle {
        color: window.color
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }
}
