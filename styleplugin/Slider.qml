import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.Slider {
    id: control

    implicitWidth: 120
    implicitHeight: 24


    handle: Item {
        id: handleBG
        x: control.visualPosition * (control.availableWidth - width)
        height: control.height
        width: control.height
        transform: Translate {
            y: control.pressed ? 2 : 0


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
            id: background
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed
        }

    }

    background: Rectangle {
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 2
        width: control.width
        height: 12
        color: ColorPalette.sunken
        radius: 6

        Rectangle {
            width: handleBG.x + handleBG.width
            height: parent.height
            radius: parent.radius

            color: ColorPalette.sunkenDark
        }
    }
}
