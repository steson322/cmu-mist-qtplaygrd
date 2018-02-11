import QtQuick 2.0
import QtQuick.Layouts 1.1
import Model 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.1
//import "qrc:///presentation/view/"

Rectangle
{
    color: "#f6f6f6"

    MainWindowVM
    {
        id: mainWindow
    }

    RowLayout {
        id: row
        spacing: 0
        anchors.fill: parent
        anchors.rightMargin: -task_bar_shadow.width

        TaskBar {
            id: task_bar
            width: 96
            Layout.fillHeight: true
            taskBar: mainWindow.taskBarViewModel
        }

        ColumnLayout {
            id: column
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            spacing: 0
            Layout.fillHeight: true
            Layout.fillWidth: true
            anchors.bottomMargin: -condition_bar_shadow.height

            ConditionBar {
                id: condition_bar
                height: 56
                Layout.fillWidth: true
                conditionBar: mainWindow.conditionBarViewModel
            }

            Item {
                Layout.fillHeight: true
                Layout.fillWidth: true

                ProtocolSectionListView {
                    id: protocol_section_list_view
                    anchors.fill: parent
                    model: mainWindow.protocolSectionListViewModel
                }
            }

            DropShadow {
                id: condition_bar_shadow
                anchors.fill: condition_bar
                verticalOffset: 3
                radius: 6.0
                samples: 16
                color: "#40000000"
                source: condition_bar
            }
        }

        DropShadow {
            id: task_bar_shadow
            anchors.fill: task_bar
            horizontalOffset: 3
            radius: 6.0
            samples: 16
            color: "#40000000"
            source: task_bar
        }
    }
}
