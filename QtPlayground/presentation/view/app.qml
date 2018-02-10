import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0

//The module Model is dynamically created from Main. This is how the backend c++ code is exposed to the UI
import Model 1.0

//import "qrc:///presentation/view"

/// Main page Item
Item {
    id: litdeco
    width: 1920
    height: 1080
    z: 0

    /// Property An array initialized with dummy values, that can be used to pass parameters among pages
    /// when loading pages with navigateTo()
    property var pageParams: { "target": "some text" }

    function navigateTo(target) {
        pageParams.currentPage = target;
        page_loader.source = target;
    }

    /// \subqml Globally available loader for all "pages" loaded using navigateTo(..),
    /// however using the loader directly is discouraged

    ColumnLayout {
        id: columnLayout
        anchors.bottomMargin: -menu_bar_shadow.height
        spacing: 0
        anchors.fill: parent

        Rectangle {
            id: menu_bar
            Layout.fillWidth: true
            height: 32
            color: "#c0c0c0"
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }

        Loader {
            id: page_loader
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        DropShadow {
            id: menu_bar_shadow
            anchors.fill: menu_bar
            verticalOffset: 3
            radius: 8.0
            samples: 16
            color: "#40000000"
            source: menu_bar
        }
    }

    /// Loads the intiial "page"
    Component.onCompleted:
    {
        navigateTo("qrc:///MainWindow.qml");
    }

}// end item Litdeco
