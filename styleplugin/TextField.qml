/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls 2 module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.9
import QtQuick.Templates 2.2 as T
import QtQuick.Controls 2.2
import QtQuick.Controls.impl 2.2
import QtGraphicalEffects 1.0
import styleplugin 1.0

T.TextField {
    id: control
    hoverEnabled: true


    implicitWidth: 120
    implicitHeight: 20

    selectByMouse: true

    leftPadding: 8
    rightPadding: 8

    color: ColorPalette.content

    selectionColor: ColorPalette.accent
    selectedTextColor: ColorPalette.contentSecondary
    verticalAlignment: TextInput.AlignVCenter


//    transform: Translate {
//        y: control.activeFocus ? 2 : 0


//        Behavior on y {
//            NumberAnimation {
//                duration: 100
//                easing {
//                    type: Easing.InOutSine
//                }
//            }
//        }
//    }

    cursorDelegate: CursorDelegate {}

    Behavior on topPadding {
        NumberAnimation {
            duration: 100
            easing {
                type: Easing.InOutSine
            }
        }
    }

    background: Item {
        id: background

//        ShadowItem {
//            anchors.fill: parent
//            hidden: control.activeFocus
//            hovered: control.hovered
//        }

        Rectangle {
            id: inputBG
            anchors.fill: parent
            color: ColorPalette.raised
            border.color: control.hovered || control.activeFocus ? ColorPalette.accent
                                          : Qt.darker(color, 1.2)
            border.width: 1
            radius: 4

            Behavior on border.color {
                ColorAnimation {
                    duration: 150
                    easing {
                        type: Easing.InOutSine
                    }
                }
            }

            PlaceholderText {
                id: placeholder
                x: control.leftPadding
                y: control.topPadding
                width: control.width - (control.leftPadding + control.rightPadding)
                height: control.height - (control.topPadding + control.bottomPadding)
                text: control.placeholderText
                font: control.font
                opacity: control.hovered || control.activeFocus ? .4 : .2
                color: ColorPalette.content
                verticalAlignment: control.verticalAlignment
                visible: !control.length && !control.preeditText
                Behavior on opacity {
                    NumberAnimation {
                        duration: 150
                        easing {
                            type: Easing.InOutSine
                        }
                    }
                }

            }
        }

    }
}
