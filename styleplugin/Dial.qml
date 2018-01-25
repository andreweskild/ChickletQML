import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.Dial {
    id: control

    width: 100
    height: 100

    background: Item {
        width: control.width
        height: width
        DialArcIndicator {
            anchors.fill: parent
            arcWidth: 12
            progress: 1.0
            color: ColorPalette.sunken
        }
        DialArcIndicator {
            anchors.fill: parent
            arcWidth: 12
            progress: control.position
            color: ColorPalette.sunkenDark
        }
    }

    handle: Item {
        id: handleItem
        x: background.x + background.width / 2 - handle.width / 2
        y: background.y + background.height / 2 - handle.height / 2
        transform: [
            Translate {
                y: -background.height * .5 + 4
            },
            Rotation {
                angle: control.angle
                origin.x: handle.width / 2
                origin.y: handle.height / 2
            }
        ]
        implicitWidth: 24
        implicitHeight: 24

        ShadowItem {
            id: shadow
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
            transform: [
                Rotation {
                    angle: -control.angle
                    origin.x: shadow.width / 2
                    origin.y: shadow.height / 2
                }
            ]
        }

        GenericInteractiveCircle {
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed
            transform: [
                Rotation {
                    angle: -control.angle
                    origin.x: shadow.width / 2
                    origin.y: shadow.height / 2
                }
            ]
        }
    }
}
