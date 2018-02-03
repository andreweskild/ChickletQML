import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.Slider {
    id: control

    implicitWidth: 120
    implicitHeight: 20


    handle: Item {
        id: handleBG
        x: orientation === Qt.Vertical ? 0 :
               control.visualPosition * (control.availableWidth - width)
        y: orientation === Qt.Vertical ? control.visualPosition * (control.availableHeight - height) :
                                         0
        height: orientation === Qt.Vertical ? control.width : control.height
        width: orientation === Qt.Vertical ? control.width : control.height
        transform: Translate {
            y: control.pressed ? 0 : -2

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
        anchors.centerIn: parent
        width: orientation === Qt.Vertical ? 10 : control.width
        height: orientation === Qt.Vertical ? control.height : 10
        color: ColorPalette.sunken
        radius: 4
        border.color: Qt.darker(color, 1.1)
        border.width: 1

        Rectangle {
            width: orientation === Qt.Vertical ? parent.width : handleBG.x + handleBG.width
            height: orientation === Qt.Vertical ?  parent.height - handleBG.y : parent.height
            y: orientation === Qt.Vertical ? handleBG.y : 0
            radius: parent.radius
            border.color: Qt.darker(color, 1.1)
            border.width: 1

            color: ColorPalette.sunkenDark
        }
    }
}
