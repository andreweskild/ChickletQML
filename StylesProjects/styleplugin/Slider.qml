import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.Slider {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight


    handle: SliderHandle {
        id: handle
        x: control.visualPosition * (control.availableWidth - width)
        height: control.height
    }

    background: Rectangle {
        anchors.centerIn: control
        width: control.width
        height: StylePlugin.dimensions.progressBarWidth
        color: StylePlugin.palette.structureLowGround
        radius: height / 2

        Rectangle {
            width: handle.x + 2
            height: parent.height
            radius: parent.radius

            color: StylePlugin.palette.actionableDark
        }
    }
}
