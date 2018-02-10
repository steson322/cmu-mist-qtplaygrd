import QtQuick 2.0
import QtQuick.Layouts 1.1
import Model 1.0
import QtGraphicalEffects 1.0

Item {
    id: item1
    width: 96

    TaskBarVM {
        id: taskBar
    }

    Rectangle {
        id: rectangle
        color: "#ebebeb"
        anchors.topMargin: 1
        anchors.fill: parent

        Column {
            id: column
            anchors.topMargin: 12
            anchors.fill: parent

            Item {
                width: 96
                height: 84

                Rectangle {
                    id: add_new
                    width: 72
                    height: 72
                    color: "#ffffff"
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr("Add New")
                        font.pixelSize: 14
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                DropShadow {
                    anchors.fill: add_new
                    radius: 6.0
                    samples: 16
                    color: "#40000000"
                    source: add_new
                }
            }

            Item {
                width: 96
                height: 84

                Rectangle {
                    id: order_by
                    width: 72
                    height: 72
                    color: "#ffffff"
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr("Order By")
                        font.pixelSize: 14
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                DropShadow {
                    anchors.fill: order_by
                    radius: 6.0
                    samples: 16
                    color: "#40000000"
                    source: order_by
                }
            }

            Item {
                width: 96
                height: 84

                Rectangle {
                    id: group_by
                    width: 72
                    height: 72
                    color: "#ffffff"
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr("Group By")
                        font.pixelSize: 14
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                DropShadow {
                    anchors.fill: group_by
                    radius: 6.0
                    samples: 16
                    color: "#40000000"
                    source: group_by
                }
            }

            Item {
                width: 96
                height: 84

                Rectangle {
                    id: filter
                    width: 72
                    height: 72
                    color: "#ffffff"
                    anchors.horizontalCenter: parent.horizontalCenter

                    Text {
                        text: qsTr("Filter")
                        font.pixelSize: 14
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }

                DropShadow {
                    anchors.fill: filter
                    radius: 6.0
                    samples: 16
                    color: "#40000000"
                    source: filter
                }
            }
        }

    }
}
