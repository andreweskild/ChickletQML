import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.MenuBarItem {
    id: control

    implicitWidth: buttonText.contentWidth + padding + padding
    implicitHeight: 20

    padding: 10

    transform: Translate {
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

    contentItem: Text {
        id: buttonText
        height: parent.height
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: control.text
        font: control.font
        color: control.hovered && !menu.isOpen ? ColorPalette.contentSecondary : ColorPalette.content


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
            hidden: control.pressed || menu.isOpen
            hovered: control.hovered
        }

        GenericInteractiveRounded {
            id: background
            anchors.fill: parent
            pressed: control.pressed && !menu.isOpen
            hovered: control.hovered && !menu.isOpen

        }
    }
}
