import QtQuick 2.9
import QtGraphicalEffects 1.0
import styleplugin 1.0

Item {
    id: root
    implicitWidth: StylePlugin.dimensions.sliderHandleWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    readonly property var control: parent


    ActionableGeneric {
        width: root.width
        height: root.height
    }

}
