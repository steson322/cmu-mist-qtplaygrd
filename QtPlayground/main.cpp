#include <QGuiApplication>
#include <QtQml>
#include <QQuickView>

#include "MainWindow/presentation/model/MainWindowViewModel.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(MainWindow);

    QGuiApplication a(argc, argv);

    // Register backend objects as Model
    qmlRegisterType<MainWindowViewModel>("Model", 1, 0, "MainWindow");

    // This call to QQuickView is to initialize the application and load the Qt runtime.
    // The source url is the url of the main qml file from the project.
    //
    QQuickView v;

    // set the window size to the size specified in the app.qml
    v.setResizeMode(QQuickView::SizeRootObjectToView);
    // v.setResizeMode(QQuickView::SizeViewToRootObject);
    v.setSource(QUrl("qrc:///app.qml"));
    v.showFullScreen();
    a.exec();
    return 0;
}
