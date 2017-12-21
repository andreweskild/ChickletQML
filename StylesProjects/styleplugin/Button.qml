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
                height: control.height
                width: control.width

                Text {
                    id: buttonText
                    anchors.centerIn: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: control.dangerous ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack
                    text: control.text
                    font: control.font

                    states: State {
                        name: "active"; when: control.hovered
                        PropertyChanges {
                            target: buttonText
                            color: StylePlugin.palette.greyWhite
                        }
                    }

                    transitions: Transition {

                        ColorAnimation {
                            duration: 100
                            easing.type: Easing.OutSine
                        }
                    }

                }
            }
}
