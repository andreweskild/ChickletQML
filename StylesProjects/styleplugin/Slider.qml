import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.Slider {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight


    handle: ActionableGeneric {
        id: handle
        x: control.visualPosition * (control.availableWidth - width)
        height: control.height
        width: StylePlugin.dimensions.sliderHandleWidth
    }

    background: Rectangle {
        anchors.centerIn: control
        width: control.width
        height: StylePlugin.dimensions.progressBarWidth
        color: StylePlugin.palette.greyDark
        radius: height / 2
        border.width: StylePlugin.dimensions.borderWidth
        border.color: StylePlugin.palette.greyBlack

        Rectangle {
            width: handle.x + handle.width
            height: parent.height
            radius: parent.radius

            color: StylePlugin.palette.greyDarkest
            border.width: StylePlugin.dimensions.borderWidth
            border.color: StylePlugin.palette.greyBlack
        }
    }
}
