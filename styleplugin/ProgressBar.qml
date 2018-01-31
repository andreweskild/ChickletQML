import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.ProgressBar {
    id: control

    implicitWidth: 120
    implicitHeight: 12


    background: Rectangle {
        anchors.fill: parent
        color: ColorPalette.sunken
        radius: 5
    }


    contentItem: Item {
        anchors.fill: parent

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            radius: 5
            color: ColorPalette.sunkenDark
        }
    }
}
