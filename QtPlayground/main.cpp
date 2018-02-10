#include <QGuiApplication>
#include <QtQml>
#include <QQuickView>

#include "MainWindow/presentation/model/MainWindowViewModel.h"
#include "MainWindow/presentation/model/ConditionBarViewModel.h"
#include "MainWindow/presentation/model/TaskBarViewModel.h"
#include "MainWindow/presentation/model/ProtocolSectionListViewModel.h"

#include "Domain/Protocol.h"
#include "Domain/Aggregation.h"
#include "Domain/ProtocolGroup.h"


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(MainWindow);

    QGuiApplication a(argc, argv);

    // Register backend objects as Model
    qmlRegisterType<MainWindowViewModel>("Model", 1, 0, "MainWindowVM");
    qmlRegisterType<ConditionBarViewModel>("Model", 1, 0, "ConditionBarVM");
    qmlRegisterType<TaskBarViewModel>("Model", 1, 0, "TaskBarVM");

    // debug
    Protocol *one = new Protocol();
    one->setName("one");
    Protocol *two = new Protocol();
    two->setName("two");
    Protocol *three = new Protocol();
    three->setName("three");

    Aggregation *odd = new Aggregation("oddOrEven", "odd");
    Aggregation *even = new Aggregation("oddOrEven", "even");

    ProtocolGroup *oddGroup = new ProtocolGroup(odd);
    oddGroup->addProtocol(one);
    oddGroup->addProtocol(three);

    ProtocolGroup *evenGroup = new ProtocolGroup(even);
    evenGroup->addProtocol(two);

    QList<ProtocolGroup*> protocolGroup = QList<ProtocolGroup*>();
    protocolGroup.append(oddGroup);
    protocolGroup.append(evenGroup);

    ProtocolSectionListViewModel *viewModel = new ProtocolSectionListViewModel(protocolGroup, nullptr);
    qInfo() << viewModel->rowCount();

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
