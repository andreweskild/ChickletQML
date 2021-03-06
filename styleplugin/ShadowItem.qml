import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

Item {
    id: root

    property bool hidden: false;
    property bool hovered: false;
    property real radius: 4;

    implicitWidth: 20
    implicitHeight: 20

//    Rectangle {
//        height: parent.height + 2
//        width: parent.width + 2
//        y: -1
//        x: -1
//        color: ColorPalette.shadow
//        opacity: hovered || hidden ? 0 : 1
//        radius: root.radius
//        Behavior on opacity {
//            NumberAnimation {
//                duration: 150
//                easing {
//                    type: Easing.InOutSine
//                }
//            }
//        }
//    }


    RectangularGlow {
        id: shadow
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: root.hovered ? 6 : 4
        height: root.height
        width: root.width - 2
        glowRadius: 5
        spread: .1
        color: ColorPalette.shadow
        cornerRadius: radius + glowRadius
        opacity: hidden ? 0 : 1
        Behavior on opacity {
            NumberAnimation {
                duration: 150
                easing {
                    type: Easing.InOutSine
                }
            }
        }
        Behavior on anchors.verticalCenterOffset {
            NumberAnimation {
                duration: 400
                easing {
                    type: Easing.OutSine
                }
            }
        }
    }
}
