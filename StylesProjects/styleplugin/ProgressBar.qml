import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.ProgressBar {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.progressBarWidth


    background: Rectangle {
        width: control.width
        height: control.height
        color: StylePlugin.palette.greyMid
        radius: height / 2
        border.width: StylePlugin.dimensions.borderWidth
        border.color: StylePlugin.palette.greyMidDark
    }


    contentItem: Item {
        implicitWidth: control.width
        implicitHeight: control.height

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            radius: height / 2
            color: StylePlugin.palette.greyMidDark
            border.width: StylePlugin.dimensions.borderWidth
            border.color: StylePlugin.palette.greyDark
        }
    }
}
