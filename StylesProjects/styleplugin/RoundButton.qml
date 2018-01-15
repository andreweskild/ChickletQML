import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.RoundButton {
    id: control

    implicitWidth: 26
    implicitHeight: 26

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

    contentItem: Text {
        id: buttonText
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: control.hovered ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack
        text: control.text
        font: control.font

        Behavior on color {
            ColorAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }
            }
        }
    }

    background: Item {
        id: content
        anchors.fill: parent

        ShadowItem {
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
            radius: parent.height * .5
        }

        GenericInteractiveCircle {
            id: background
            anchors.fill: parent
            pressed: control.pressed
            hovered: control.hovered
        }
    }
}
