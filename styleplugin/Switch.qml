import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.Switch {
    id: control

    implicitWidth: Dimensions.switchWidth
    implicitHeight: Dimensions.commonHeight

    padding: 8
    spacing: 8

    indicator: Item {
        x: control.checked ? control.width - width: 0
        width: control.height
        height: control.height
        transform: Translate {
            y: control.pressed ? Dimensions.elevation : 0


            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }

        ShadowItem {
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
        }

        GenericInteractiveRounded {
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed
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
        y: Dimensions.elevation


        Rectangle {
            anchors.fill: parent
            color: control.checked ? ColorPalette.sunkenDark : ColorPalette.sunken
            radius: Dimensions.cornerRadius
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
                width: Dimensions.indicatorWidth
                height: 10
                anchors.centerIn: parent
                color: control.checked ? ColorPalette.contentSecondary : ColorPalette.content
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
                width: 12
                height: 12
                anchors.centerIn: parent
                color: "transparent"
                radius: height * .5
                border.width: Dimensions.indicatorWidth
                border.color: control.checked ? ColorPalette.contentSecondary : ColorPalette.content
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
