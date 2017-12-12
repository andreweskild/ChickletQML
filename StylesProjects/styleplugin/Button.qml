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

    contentItem: ActionableGeneric {
        id: buttonBackground
        pressed: control.down
        hovered: control.hovered
        dangerous: control.dangerous

        Text {
            id: buttonText
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: control.dangerous ? StylePlugin.palette.textLight : StylePlugin.palette.textDark
            text: control.text
            font: control.font

            states: State {
                name: "active"; when: control.hovered
                PropertyChanges {
                    target: buttonText
                    color: StylePlugin.palette.textLight
                }
            }

            transitions: Transition {

                ColorAnimation {
                    duration: 200
                    easing.type: Easing.InOutSine
                }
            }

        }
    }
}
