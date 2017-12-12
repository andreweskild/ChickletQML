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

    property bool pressed
    property bool dangerous
    property bool hovered
    property real radius: StylePlugin.dimensions.actionableRadius

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


        ActionableSurface {
            id: gradientHighlight
            color: StylePlugin.palette.actionableMain
            gradient.mainColor: root.dangerous ? StylePlugin.palette.dangerMain : StylePlugin.palette.activeMain
            gradient.secondaryColor: root.dangerous ? StylePlugin.palette.dangerDark : StylePlugin.palette.activeHighlight
            gradient.border.color: root.dangerous ? StylePlugin.palette.dangerDark : StylePlugin.palette.activeDark
            pressedColor: root.dangerous ? StylePlugin.palette.dangerDark : StylePlugin.palette.activeDark
            pressedBorderColor: root.dangerous ? StylePlugin.palette.dangerDarkest : StylePlugin.palette.activeDarkest
            width: root.width
            height: root.height
            border.color: root.dangerous ? StylePlugin.palette.dangerDark : StylePlugin.palette.actionableDark
            border.width: StylePlugin.dimensions.borderWidth
            radius: root.radius
            pressed: root.pressed
            hovered: root.hovered
        }
    }

    states: [
        State {
            name: "down"; when: root.pressed
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
            to: "down"
            animations: [
                NumberAnimation {
                    duration: 100
                    properties: "opacity";
                    easing.type: Easing.OutSine
                },
                NumberAnimation {
                    duration: 100
                    properties: "y";
                    easing.type: Easing.OutSine
                }
            ]
        },
        Transition {
            animations: [
                    NumberAnimation {
                        duration: 100
                        properties: "opacity";
                        easing.type: Easing.OutSine
                    },
                    ColorAnimation {
                        duration: 50
                        easing.type: Easing.InOutSine
                    }
            ]
        }
    ]

}
