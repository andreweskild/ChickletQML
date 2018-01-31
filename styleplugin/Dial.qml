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
            arcWidth: 10
            progress: 1.0
            color: ColorPalette.sunken
        }
        DialArcIndicator {
            id: arcProgress
            anchors.fill: parent
            arcWidth: 10
            progress: control.position
            color: ColorPalette.sunkenDark
        }
    }

    handle: Item {
        id: handleItem
        x: arcProgress.endPoint.x - handle.width / 2
        y: arcProgress.endPoint.y - handle.height / 2
//        transform: [
//            Translate {
//                y: -background.height * .5 + 4
//            },
//            Rotation {
//                angle: control.angle
//                origin.x: handle.width / 2
//                origin.y: handle.height / 2
//            },
//            Translate {
//                y: control.pressed ? 2 : 0


//                Behavior on y {
//                    NumberAnimation {
//                        duration: 100
//                        easing {
//                            type: Easing.InOutSine
//                        }
//                    }
//                }
//            }
//        ]
        implicitWidth: 20
        implicitHeight: 20

        ShadowItem {
            id: shadow
            anchors.fill: parent
            hidden: control.pressed
            hovered: control.hovered
            radius: height / 2
//            transform: [
//                Rotation {
//                    angle: -control.angle
//                    origin.x: shadow.width / 2
//                    origin.y: shadow.height / 2
//                }
//            ]
        }

        GenericInteractiveCircle {
            anchors.fill: parent
            hovered: control.hovered
            pressed: control.pressed
//            transform: [
//                Rotation {
//                    angle: -control.angle
//                    origin.x: shadow.width / 2
//                    origin.y: shadow.height / 2
//                }
//            ]
        }
    }

}
