import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.Button {
    id: control

    property bool dangerous: false

    implicitWidth: StylePlugin.dimensions.actionableNormalWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    contentItem: Item {
            id: content
            anchors.fill: parent

            ShadowItem {
                anchors.fill: parent
                hidden: control.pressed
            }

            InteractiveGradient {
                id: background
                height: parent.height
                width: parent.width
                pressed: control.pressed
                hovered: control.hovered

                y: control.pressed ? 2 : 0

                Behavior on y {
                    NumberAnimation {
                        duration: 100
                        easing {
                            type: Easing.OutSine
                            overshoot: 5
                        }
                    }
                }

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
                            duration: 100
                            easing {
                                type: Easing.OutSine
                            }
                        }
                    }
                }
            }
    }
}
