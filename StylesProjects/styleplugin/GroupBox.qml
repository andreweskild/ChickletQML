import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import styleplugin 1.0

T.GroupBox {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            label ? label.implicitWidth + leftPadding + rightPadding : 0,
                            contentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(background ? background.implicitHeight : 0, contentHeight + topPadding + bottomPadding)

    contentWidth: contentItem.implicitWidth || (contentChildren.length === 1 ? contentChildren[0].implicitWidth : 0)
    contentHeight: contentItem.implicitHeight || (contentChildren.length === 1 ? contentChildren[0].implicitHeight : 0)

    spacing: 6
    padding: 12
    topPadding: padding + (label && label.implicitWidth > 0 ? label.implicitHeight + spacing : 0)

    label: Text {
        x: control.leftPadding
        width: control.availableWidth

        text: control.title
        font: control.font
        color: StylePlugin.palette.greyDark
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        y: control.topPadding - control.padding
        width: parent.width
        height: parent.height - control.topPadding + control.padding

        radius: StylePlugin.dimensions.actionableRadius
        color: "transparent"
        border.color: StylePlugin.palette.greyMid
        border.width: StylePlugin.dimensions.borderWidth
    }
}
