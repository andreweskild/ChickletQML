import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

Item {
    id: root

    property bool hidden: false;

    implicitWidth: 24
    implicitHeight: 24

    opacity: hidden ? 0 : 1

    Behavior on opacity {
        NumberAnimation {
            duration: 100
            easing {
                type: Easing.OutSine
            }
        }
    }

    RectangularGlow {
        id: shadow
        y: 6
        x: 3
        height: root.height - 6
        width: root.width - 6
        glowRadius: 5
        spread: 0.2
        color: StylePlugin.palette.shadow
        cornerRadius: StylePlugin.dimensions.actionableRadius + glowRadius
    }
}
