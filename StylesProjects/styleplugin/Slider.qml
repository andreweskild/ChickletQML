import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.Slider {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    ToolTip {
        x: handle.x - width * .5 + leftPadding + padding
        text: control.value.toFixed(1)
        delay: 1000
        visible: control.hovered
    }

    handle: Item {
        id: handle
        x: control.visualPosition * (control.availableWidth - width)
        height: control.height
        width: control.height
        y: control.pressed ? 2 : 0

        Behavior on y {
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.InOutSine
                }
            }
        }

        ShadowItem {
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
        }

        GenericInteractiveRounded {
            id: background
            anchors.fill: parent
        }

    }

    background: Rectangle {
        width: control.width
        height: 24
        color: StylePlugin.palette.greyMid
        radius: 4
        y: 2

        Rectangle {
            width: handle.x + handle.width
            height: parent.height
            radius: parent.radius

            color: StylePlugin.palette.greyDark
        }
    }
}
