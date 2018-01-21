import QtQuick 2.10
import QtQuick.Templates 2.3 as T
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.TabBar {
    id: control

    implicitWidth: Math.max(background ? background.implicitWidth : 0,
                            contentWidth + leftPadding + rightPadding + spacing)
    implicitHeight: Math.max(background ? background.implicitHeight : 0,
                             contentHeight + topPadding + bottomPadding) + 4

    leftPadding: 8
    rightPadding: 8
    spacing: 8

    clip: true

    background: Item {
        anchors.fill: parent
        Rectangle {
            anchors.fill: parent
            color: ColorPalette.sunken
        }

        LinearGradient {
            anchors.bottom: parent.bottom
            width: parent.width
            height: 4
            start: Qt.point(0, 0)
            end: Qt.point(0, 8)
            cached: true
            gradient: Gradient {
                        GradientStop { position: 0.0; color: "transparent" }
                        GradientStop { position: 1.0; color: ColorPalette.shadow }
                    }
        }


    }

    contentItem: ListView {
        model: control.contentModel
        currentIndex: control.currentIndex

        spacing: control.spacing
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds
        flickableDirection: Flickable.HorizontalFlick

        highlightMoveDuration: 250
        highlightResizeDuration: 0
        highlightFollowsCurrentItem: true
        highlightRangeMode: ListView.ApplyRange
        preferredHighlightBegin: 48
        preferredHighlightEnd: width - 48

    }

}
