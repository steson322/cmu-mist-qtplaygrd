import QtQuick 2.0
import QtQuick.Layouts 1.1
import Model 1.0
import QtGraphicalEffects 1.0

Item {
    height: 56
    property var conditionBar

    Rectangle {
        id: rectangle
        color: "#558abf"
        anchors.fill: parent

        RowLayout {
            id: rowLayout
            anchors.leftMargin: 15
            spacing: 0
            anchors.fill: parent

            ListView {
                id: listView
                spacing: 10
                Layout.fillHeight: true
                Layout.fillWidth: true
                orientation: ListView.Horizontal
                interactive: false
                model: conditionBar.configurationNames

                delegate: Item {
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: childrenRect.width
                    Rectangle {
                        id: rectangle_1
                        width: childrenRect.width
                        height: 25
                        color: "#ff8351"
                        anchors.verticalCenter: parent.verticalCenter
                        radius: 5
                        RowLayout {
                            id: column
                            width: text1.width + 35
                            spacing: 0

                            Item {
                                id: item1
                                width: text1.width + 10

                                Text {
                                    id: text1
                                    x: 5
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                    text: qsTr(modelData)
                                    anchors.verticalCenterOffset: 0
                                    font.pixelSize: 14
                                }
                            }

                            Item {
                                id: item2
                                width: 25
                                height: 25
                                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

                                Text {
                                    id: remove1
                                    text: qsTr("X")
                                    font.family: "Verdana"
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                    font.pixelSize: 14
                                }

                                MouseArea {
                                    anchors.fill: parent
                                    onClicked: conditionBar.remove(modelData)
                                }
                            }
                        }
                    }

                    DropShadow {
                        anchors.fill: rectangle_1
                        radius: 9.0
                        samples: 16
                        color: "#40000000"
                        source: rectangle_1
                    }
                }
            }

            Item {
                id: item3
                width: 100
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                Layout.fillHeight: true

                Text {
                    id: textEdit
                    width: 80
                    height: 20
                    color: "#ffffff"
                    text: qsTr("Clear All")
                    font.family: "Verdana"
                    horizontalAlignment: Text.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: conditionBar.removeAll()
                }
            }
        }
    }

}
