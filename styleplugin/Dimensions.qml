pragma Singleton
import QtQuick 2.9

QtObject {
    id: dimensionsCollection

    readonly property int commonWidthMini: 72
    readonly property int commonWidth: 96
    readonly property int commonWidthWide: 120

    readonly property int drawerWidth: 200

    readonly property int commonHeight: 24

    readonly property int commonPadding: 8

    readonly property int progressBarWidth: 8

    readonly property int indicatorWidth: 3

    readonly property int switchWidth: 48

    readonly property int cornerRadius: 4
    readonly property int borderWidth: 2

    readonly property int elevation: 2

}
