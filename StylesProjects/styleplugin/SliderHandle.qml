import QtQuick 2.9
import QtGraphicalEffects 1.0
import styleplugin 1.0

Item {
    id: root
    implicitWidth: StylePlugin.dimensions.sliderHandleWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    property real value: 0
    property bool handleHasFocus: false
    property bool handlePressed: false
    property bool handleHovered: false
    readonly property int initialSize: 13
    readonly property var control: parent


    ActionableGeneric {
        width: root.width
        height: root.height
        isActive: control.hovered
        isDown: control.pressed
    }

}
