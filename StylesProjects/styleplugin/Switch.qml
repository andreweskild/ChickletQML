import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.Switch {
    id: control

    implicitWidth: 48
    implicitHeight: StylePlugin.dimensions.actionableHeight

    padding: 8
    spacing: 8

    indicator: Item {
        x: control.checked ? control.width - width: 0
        width: StylePlugin.dimensions.actionableHeight
        height: StylePlugin.dimensions.actionableHeight

        ShadowItem {
            height: parent.height
            width: parent.width
            hidden: control.pressed
            hovered: control.hovered
        }

        GenericInteractiveRounded {
            width: parent.width
            height: parent.height
        }

        Behavior on x {
            NumberAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }
            }
        }
    }


    background: Item {
        width: parent.width
        height: parent.height
        y: 2


        Rectangle {
            anchors.fill: parent
            color: control.checked ? StylePlugin.palette.greyDark : StylePlugin.palette.greyMid
            radius: StylePlugin.dimensions.actionableRadius + 1
            Behavior on color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        Item {
            height: parent.height
            width: parent.width * .5
            anchors.left: parent.left

            Rectangle {
                width: 2
                height: 10
                anchors.centerIn: parent
                color: control.checked ? StylePlugin.palette.greyMid : StylePlugin.palette.greyDark
                radius: 2
                Behavior on color {
                    ColorAnimation {
                        duration: 150
                        easing {
                            type: Easing.InOutSine
                        }
                    }
                }
            }
        }
        Item {
            height: parent.height
            width: parent.width * .5
            anchors.right: parent.right

            Rectangle {
                width: 10
                height: 10
                anchors.centerIn: parent
                color: "transparent"
                radius: height * .5
                border.width: 2
                border.color: control.checked ? StylePlugin.palette.greyMid : StylePlugin.palette.greyDark
                Behavior on border.color {
                    ColorAnimation {
                        duration: 150
                        easing {
                            type: Easing.InOutSine
                        }
                    }
                }
            }
        }
    }
}
