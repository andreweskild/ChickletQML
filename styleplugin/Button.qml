import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.Button {
    id: control

    property bool dangerous: false

    implicitWidth: Dimensions.commonWidth
    implicitHeight: Dimensions.commonHeight

    transform: Translate {
        y: control.pressed ? Dimensions.elevation : 0


        Behavior on y {
            NumberAnimation {
                duration: 100
                easing {
                    type: Easing.InOutSine
                }
            }
        }
    }

    contentItem:Text {
        id: buttonText
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: control.dangerous ?
            ColorPalette.contentSecondary :
            (control.hovered ? ColorPalette.contentSecondary : ColorPalette.content)
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
        }

        GenericInteractiveRounded {
            id: background
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed
            dangerous: control.dangerous
        }
}
}
