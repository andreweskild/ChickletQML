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


    implicitWidth: StylePlugin.dimensions.actionableWideWidth
    implicitHeight: StylePlugin.dimensions.actionableHeight

    selectByMouse: true

    leftPadding: 8
    rightPadding: 8

    selectionColor: StylePlugin.palette.activeMain
    selectedTextColor: StylePlugin.palette.textLight
    verticalAlignment: TextInput.AlignVCenter



    background: Item {
        id: background
        RectangularGlow {
            id: shadow
            y: 6
            x: 3
            height: inputBG.height - 6
            width: inputBG.width - 6
            glowRadius: 5
            spread: 0.2
            color: StylePlugin.palette.shadow
            cornerRadius: StylePlugin.dimensions.actionableRadius + glowRadius
            opacity: 1
        }

        Rectangle {
            id: inputBG
            height: control.height
            width: control.width
            color: StylePlugin.palette.actionableMain
            border.color: StylePlugin.palette.actionableDark
            border.width: StylePlugin.dimensions.borderWidth
            radius: StylePlugin.dimensions.actionableRadius


            PlaceholderText {
                id: placeholder
                x: control.leftPadding
                y: control.topPadding
                width: control.width - (control.leftPadding + control.rightPadding)
                height: control.height - (control.topPadding + control.bottomPadding)
                text: control.placeholderText
                font: control.font
                color: StylePlugin.palette.actionableDark
                verticalAlignment: control.verticalAlignment
                elide: Text.ElideRight
                visible: !control.length && !control.preeditText && (!control.activeFocus || control.horizontalAlignment !== Qt.AlignHCenter)
            }
        }

    }

    states: [
        State {
            name: "hovered"; when: control.hovered && !control.activeFocus
            changes: [
                PropertyChanges {
                    target: inputBG
                    border.color: StylePlugin.palette.activeDark
                }
            ]
        },
        State {
            name: "focused"; when: control.activeFocus
            changes: [
                PropertyChanges {
                    target: shadow
                    opacity: 0
                },
                PropertyChanges {
                    target: placeholder
                    opacity: .5
                },
                PropertyChanges {
                    target: inputBG
                    border.color: StylePlugin.palette.activeDark
                },
                PropertyChanges {
                    target: control
                    y: 2
                }
            ]
        }
    ]

    transitions: [
         Transition {
            reversible: true
            animations: [
                ColorAnimation {
                    duration: 100
                    easing.type: Easing.OutSine
                },
                NumberAnimation {
                    duration: 100
                    properties: "opacity"
                    easing.type: Easing.OutSine
                },
                NumberAnimation {
                    duration: 100
                    properties: "y"
                    easing.type: Easing.OutSine
                }
            ]
         }
     ]
}
