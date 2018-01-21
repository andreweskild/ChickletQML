import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.ApplicationWindow {
    id: window

    color: ColorPalette.window

    Behavior on color {
        ColorAnimation {
            duration: 150
            easing {
                type: Easing.InOutSine
            }
        }
    }
    overlay.modal: Rectangle {
        color: window.color
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }

    overlay.modeless: Rectangle {
        color: window.color
        Behavior on opacity { NumberAnimation { duration: 150 } }
    }
}
