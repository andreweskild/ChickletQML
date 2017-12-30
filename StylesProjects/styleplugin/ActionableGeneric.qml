import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

Item {
    id: root

    implicitWidth: 24
    implicitHeight: 24

    readonly property Item control: parent

    Item {
        id: visualElements
        width: root.width
        height: root.height

        RectangularGlow {
            id: shadow
            y: 6
            x: 3
            height: gradientHighlight.height - 6
            width: gradientHighlight.width - 6
            glowRadius: 5
            spread: 0.2
            color: StylePlugin.palette.shadow
            cornerRadius: StylePlugin.dimensions.actionableRadius + glowRadius
        }


        InteractiveGradient {
            id: gradientHighlight
            anchors.fill: parent
            pressed: control.pressed
        }
    }

    states: [
        State {
            name: "down"; when: control.pressed;
            changes: [
                PropertyChanges {
                    target: shadow
                    opacity: 0
                } ,
                PropertyChanges {
                    target: root
                    y: 2
                }

            ]
        }
    ]

    transitions: [
        Transition {
            reversible: true
            animations: [
                NumberAnimation {
                    duration: 100
                    properties: "opacity";
                    easing.type: Easing.OutSine
                },
                NumberAnimation {
                    duration: 50
                    properties: "y";
                    easing.type: Easing.OutSine
                },
                ColorAnimation {
                    duration: 100
                    easing.type: Easing.OutSine
                }
            ]
        }
    ]

}
