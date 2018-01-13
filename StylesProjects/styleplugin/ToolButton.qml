import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtQuick.Controls 2.3
import QtQuick.Controls.impl 2.3
import styleplugin 1.0

T.ToolButton {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableMiniWidth
    implicitHeight: 24


    background: Item {
        anchors.fill: parent

        ShadowItem {
            height: parent.height
            width: parent.width
            hidden: control.pressed
            hovered: control.hovered
        }

        GenericInteractiveRounded {
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
