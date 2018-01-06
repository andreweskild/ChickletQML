import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.Slider {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight


    handle: Item {
        id: handle
        x: control.visualPosition * (control.availableWidth - width)
        height: control.height
        width: StylePlugin.dimensions.sliderHandleWidth
        y: control.pressed ? 2 : 0

        Behavior on y {
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.OutSine
                }
            }
        }

        ShadowItem {
            anchors.fill: parent
            hidden: control.pressed
        }

        InteractiveButton {
            id: background
            anchors.fill: parent
            pressed: control.pressed
            hovered: control.hovered
        }
    }

    background: Rectangle {
        anchors.centerIn: control
        width: control.width
        height: StylePlugin.dimensions.progressBarWidth
        color: StylePlugin.palette.greyMid
        radius: height / 2

        Rectangle {
            width: handle.x + handle.width
            height: parent.height
            radius: parent.radius

            color: StylePlugin.palette.greyDark
        }
    }
}
