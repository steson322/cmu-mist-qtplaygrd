import QtQuick 2.0
import QtQuick.Layouts 1.1
import Model 1.0

Item {
    height: 56
    property alias item1: item1

    ConditionBarVM {
        id: conditionBar
    }

    Rectangle {
        id: rectangle
        color: "#558abf"
        anchors.fill: parent

        ListView {
            id: listView
            spacing: 10
            anchors.fill: parent
            orientation: ListView.Horizontal
            interactive: false

            model: ["Test Data", "Test Data2"]
            //conditionBar.configNames

            delegate: Rectangle {
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: text1.width + 100
                color: "#ff0000"
                Rectangle {
                    id: rectangle1
                    width: text1.width + 100
                    height: 25
                    color: "#ff8351"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    radius: 5
                    RowLayout {
                        id: column
                        anchors.fill: parent
                        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                        spacing: 0
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Item {
                            id: item1
                            Layout.fillHeight: true
                            Layout.fillWidth: true

                            Text {
                                id: text1
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: qsTr(modelData)
                                anchors.fill: parent
                                color: "#ffffff"
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
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: qsTr("X")
                                anchors.fill: parent
                                color: "#ffffff"
                                font.pixelSize: 14
                            }
                        }
                    }
                }
            }

            Text {
                id: text2
                x: 261
                y: 27
                color: "#ffffff"
                text: "Text"
                font.family: "Verdana"
                font.pixelSize: 14
            }
        }
    }

}
