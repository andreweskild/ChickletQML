import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.RoundButton {
    id: control

    implicitWidth: 26
    implicitHeight: 26


    contentItem: Item {
            id: content
            anchors.fill: parent

            ShadowItem {
                height: parent.height
                width: parent.width
                hidden: control.pressed
                hovered: control.hovered
                radius: parent.height * .5
            }

            GenericInteractiveCircle {
                id: background
                height: parent.height
                width: parent.width

                Text {
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
            }
    }
}
