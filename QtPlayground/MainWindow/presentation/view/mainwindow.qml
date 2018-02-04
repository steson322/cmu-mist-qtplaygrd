import QtQuick 2.0
import Model 1.0
import "qrc:///presentation/view/"

Rectangle
{
    id: main_window

    Text {
        id: text1
        x: 252
        y: 206
        width: 136
        height: 54
        text: qsTr("Hello World!")
        font.pixelSize: 24
    }
}
