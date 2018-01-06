import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.MenuBarItem {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableMiniWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight
    baselineOffset: contentItem.y + contentItem.baselineOffset


    contentItem: Text {
        height: parent.height
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: control.text
        font: control.font
        color: control.hovered && !menu.isOpen ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack

        y: control.pressed || menu.isOpen ? 2 : 0

        Behavior on y {
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.InOutSine
                    overshoot: 5
                }
            }
        }

        Behavior on color {
            ColorAnimation {
                duration: 200
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
            hidden: control.pressed || menu.isOpen
        }

        InteractiveButton {
        id: background
        height: menu.opened ? control.height + 4 : control.height
        width: control.width
        pressed: control.pressed && !menu.isOpen
        hovered: control.hovered && !menu.isOpen

        y: control.pressed || menu.isOpen ? 2 : 0

            Behavior on y {
                NumberAnimation {
                    duration: 100
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }
        }
    }
}
