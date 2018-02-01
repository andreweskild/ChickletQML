import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.SwipeDelegate {
    id: control

    implicitWidth: 96
    implicitHeight: 20


    swipe.transition: Transition { SmoothedAnimation { velocity: 3; easing.type: Easing.InOutCubic } }

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

    contentItem: Label {
        leftPadding: 10
        height: parent.height
        width: parent.width
        verticalAlignment: Text.AlignVCenter
        text: control.text
        font: control.font
        color: control.hovered ? ColorPalette.contentSecondary : ColorPalette.content
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
        height: parent.height
        width: parent.width

        GenericInteractiveRect {
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed
        }
    }
}
