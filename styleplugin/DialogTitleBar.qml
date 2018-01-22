import QtQuick 2.10
import QtQuick.Controls 2.3
import styleplugin 1.0

Item {
    readonly property Item dialog: parent
    height: Dimensions.commonHeight
    clip: true
    Rectangle {
        id: background
        width: parent.width
        height: parent.height + radius
        color: ColorPalette.raised
        radius: Dimensions.cornerRadius
    }
    Label {
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        leftPadding: Dimensions.commonPadding
        text: control.title
        visible: control.title
        font.bold: true
        color: ColorPalette.content
    }
}
