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
                height: parent.height
                width: parent.width
                hidden: control.pressed
                hovered: control.hovered
            }

            GenericInteractiveRounded {
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
