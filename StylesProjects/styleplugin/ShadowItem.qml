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

    implicitWidth: 24
    implicitHeight: 24



    RectangularGlow {
        id: shadow
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: root.hovered ? 4 : 2
        height: root.height
        width: root.width
        glowRadius: 3
        spread: 0.2
        color: StylePlugin.palette.shadow
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
