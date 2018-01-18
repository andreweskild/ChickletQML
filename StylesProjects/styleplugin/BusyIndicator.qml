import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import styleplugin 1.0

T.BusyIndicator {
    id: control

    implicitWidth: 24
    implicitHeight: 24

    contentItem: BusyIndicatorArc {
        id: indicator
        anchors.fill: parent
        color: StylePlugin.palette.greyDark
        arcWidth: 8

        SequentialAnimation {
            running: control.running
            loops: Animation.Infinite
            NumberAnimation {
                target: indicator
                duration: 400;
                property: "arcLength";
                to: 270
                easing {
                    type: Easing.InCubic
                }
            }
            NumberAnimation {
                target: indicator
                duration: 400;
                property: "arcLength";
                to: 120
                easing {
                    type: Easing.OutCubic
                }
            }
        }

        states: State {
            name: "running"; when: control.running;
            PropertyChanges { target: indicator; rotation: 360 }
        }

        transitions: Transition {
            animations: [
                RotationAnimation {
                    duration: 800;
                    loops: Animation.Infinite
                    easing {
                        type: Easing.InOutCubic
                    }
                }
            ]
        }
    }


    background: Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: StylePlugin.palette.greyMid
        border.width: indicator.arcWidth
        radius: width * .5
    }
}
