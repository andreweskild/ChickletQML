import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import styleplugin 1.0

T.MenuItem {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: StylePlugin.dimensions.actionableHeight



    contentItem: Text {
        leftPadding: !control.mirrored ? 8 : arrowPadding
        rightPadding: control.mirrored ? 8 : arrowPadding
        height: parent.height

        verticalAlignment: Text.AlignVCenter
        text: control.text
        font: control.font
        color: control.hovered ? StylePlugin.palette.greyWhite : StylePlugin.palette.greyBlack
    }

    background: InteractiveGradient {
        geometryMode: InteractiveGradient.Rect
        implicitWidth: 200
        implicitHeight: parent.height
        hovered: control.hovered
        pressed: control.pressed
    }
}
