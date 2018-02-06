import QtQuick 2.0
import QtQuick.Layouts 1.1
import Model 1.0
//import "qrc:///presentation/view/"

Rectangle
{
    id: mainWindow
    color: "#f6f6f6"

    MainWindow
    {
        id: loginModel
    }

    Text {
        id: text1
        x: 104
        y: 66
        width: 136
        height: 54
        text: qsTr("Hello World!")
        font.pixelSize: 24
    }

    RowLayout {
        spacing: 0
        anchors.fill: parent

        TaskBar {
            id: taskBar
            width: 96
            Layout.fillHeight: true
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            spacing: 0
            Layout.fillHeight: true
            Layout.fillWidth: true

            ConditionBar {
                id: conditionBar
                height: 56
                Layout.fillWidth: true
            }
        }
    }
}
