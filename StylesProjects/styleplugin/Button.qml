import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.Button {
    id: control

    implicitWidth: StylePlugin.dimensions.actionableNormalWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    onPressed: {
        console.log("pressed")
    }

    contentItem: Item {
        id: buttonContent
        width: control.width
        height: control.height

        Rectangle {
            id: buttonBackground
            height: parent.height
            width: parent.width
            radius: StylePlugin.dimensions.actionableRadius
            color: StylePlugin.palette.actionableMain
            border.color: StylePlugin.palette.actionableDark
            border.width: StylePlugin.dimensions.borderWidth
        }

        ActionableSurface {
            id: gradientHighlight
            mainActiveColor: StylePlugin.palette.activeMain
            secondaryActiveColor: StylePlugin.palette.activeHighlight
            mainColor: StylePlugin.palette.actionableMain
            activeBorderColor: StylePlugin.palette.activeDark
            width: parent.width
            height: parent.height
            border.color: StylePlugin.palette.actionableDark
            border.width: StylePlugin.dimensions.borderWidth
            radius: StylePlugin.dimensions.actionableRadius
            opacity: 0

            onOpacityChanged: {
                if (opacity == 0)
                {
                    enabled: false;
                }
                else
                {
                    enabled: true;
                }
            }
        }

        Text {
            id: buttonText
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: StylePlugin.palette.textDark
            text: control.text
            font: control.font
        }

        ColorAnimation {
                id: animateHoverText
                target: buttonText
                properties: "color"
                from: control.hovered ? StylePlugin.palette.textLight : StylePlugin.palette.textDark
                to: control.hovered ? StylePlugin.palette.textDark : StylePlugin.palette.textLight
                duration: 100
                easing.type: Easing.OutSine
        }

    }

    background: Item {
        height: parent.height
        width: parent.width

        RectangularGlow {
            id: shadow
            y: 6
            x: 3
            height: buttonBackground.height - 6
            width: buttonBackground.width - 6
            glowRadius: 10
            spread: 0.2
            color: StylePlugin.palette.shadow
            cornerRadius: StylePlugin.dimensions.actionableRadius + glowRadius
            opacity: 1
        }


    }

    states: [
        State {
            name: "down"; when: control.down
            changes: [
                PropertyChanges {
                    target: shadow
                    opacity: 0
                } ,
                PropertyChanges {
                    target: buttonContent
                    y: 2
                } ,
                PropertyChanges {
                    target: buttonBackground
                    color: StylePlugin.palette.activeDark
                    border.color: StylePlugin.palette.activeDarkest
                } ,
                PropertyChanges {
                    target: buttonText
                    color: StylePlugin.palette.textLight
                }

            ]
        },
        State {
            name: "hovered"; when: control.hovered
            changes: [
                PropertyChanges {
                    target: gradientHighlight
                    opacity: 1
                },
                PropertyChanges {
                    target: buttonText
                    color: StylePlugin.palette.textLight
                },
                PropertyChanges {
                    target: buttonBackground
                    color: StylePlugin.palette.activeMain
                    border.color: StylePlugin.palette.activeDark
                }
            ]
        }
    ]

    transitions: [
        Transition {
            to: "hovered"
            animations: [
                NumberAnimation {
                    duration: 150
                    properties: "opacity";
                    easing.type: Easing.OutSine
                },
                NumberAnimation {
                    duration: 100
                    properties: "y";
                    easing.type: Easing.OutSine
                },
                ColorAnimation {
                    duration: 150
                    easing.type: Easing.InOutSine
                }
            ]
        },
        Transition {
            to: "down"
            animations: [
                PropertyAction {
                    target: buttonBackground;
                    property: "color"
                },
                NumberAnimation {
                    duration: 100
                    properties: "opacity";
                    easing.type: Easing.OutSine
                },
                NumberAnimation {
                    duration: 100
                    properties: "y";
                    easing.type: Easing.OutSine
                },
                ColorAnimation {
                    duration: 100
                    easing.type: Easing.InOutSine
                }
            ]
        }
    ]

}
