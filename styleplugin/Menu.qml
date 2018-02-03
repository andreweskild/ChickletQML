import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Templates 2.3 as T
import styleplugin 1.0


T.Menu {
    id: control

    implicitWidth: 120
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentItem ? contentItem.implicitHeight : 0) + topPadding + bottomPadding

    property bool isOpen: false

    topPadding: 5
    bottomPadding: 5



    transformOrigin: !cascade ? Item.Top : (mirrored ? Item.TopRight : Item.TopLeft)

    delegate: MenuItem {}

    enter: Transition {
        // grow_fade_in
        NumberAnimation { property: "scale"; from: 0.9; to: 1.0; easing.type: Easing.OutQuint; duration: 220 }
        NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; easing.type: Easing.OutCubic; duration: 150 }
        PropertyAction { target: control; property: "isOpen"; value: true }
    }

    exit: Transition {
        // shrink_fade_out
        NumberAnimation { property: "scale"; from: 1.0; to: 0.9; easing.type: Easing.OutQuint; duration: 220 }
        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; easing.type: Easing.OutCubic; duration: 150 }
        PropertyAction { target: control; property: "isOpen"; value: false }
    }

    contentItem: ListView {
        implicitHeight: contentHeight

        model: control.contentModel
        interactive: ApplicationWindow.window ? contentHeight > ApplicationWindow.window.height : false
        currentIndex: control.currentIndex

        ScrollIndicator.vertical: ScrollIndicator {}
    }

    background: Item {
        id: background
        width: control.width
        height: control.height

        ShadowItem {
            anchors.fill: parent
        }

        Rectangle {
            height: parent.height
            width: parent.width
            color: ColorPalette.raised
            radius: 4


        }

        Rectangle {
            color: ColorPalette.raised
            width: control.parent.width >= control.width ? control.width :
                                                          control.parent.width
            y: -5
            height: 10
        }


    }
}
