import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.SwipeDelegate {
    id: control

    implicitWidth: 96
    implicitHeight: 24

    clip: true

    swipe.transition: Transition { SmoothedAnimation { velocity: 3; easing.type: Easing.InOutCubic } }

    contentItem: Label {
        leftPadding: 8
        height: parent.height
        width: parent.width
        verticalAlignment: Text.AlignVCenter
        text: control.text
        font: control.font
        color: control.hovered ? ColorPalette.contentSecondary : ColorPalette.content
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
