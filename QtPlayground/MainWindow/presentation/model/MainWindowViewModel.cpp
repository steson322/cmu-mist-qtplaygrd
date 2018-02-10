#include "MainWindowViewModel.h"

MainWindowViewModel::MainWindowViewModel(QObject * parent) :
    QObject(parent),
    protocolSectionListViewModel(new ProtocolSectionListViewModel(this)),
    taskBarViewModel(new TaskBarViewModel(this)),
    conditionBarViewModel(new ConditionBarViewModel(this))
{
    connect(taskBarViewModel, SIGNAL(orderByChanged()), SLOT(handleOrderBy()));
    connect(taskBarViewModel, SIGNAL(groupByChanged()), SLOT(handleGroupBy()));
    connect(taskBarViewModel, SIGNAL(filterChanged()), SLOT(handleFilter()));
}

MainWindowViewModel::~MainWindowViewModel()
{
}

TaskBarViewModel *MainWindowViewModel::getTaskBarViewModel() const
{
    return taskBarViewModel;
}

ConditionBarViewModel *MainWindowViewModel::getConditionBarViewModel() const
{
    return conditionBarViewModel;
}

ProtocolSectionListViewModel *MainWindowViewModel::getProtocolSectionListViewModel() const
{
    return protocolSectionListViewModel;
}

void MainWindowViewModel::handleOrderBy()
{
    qDebug( "Order By Change Received");
    conditionBarViewModel->changeOrderBy();
    protocolSectionListViewModel->updateProtocols(this->getProtocolGroupsOne());
}

void MainWindowViewModel::handleGroupBy()
{
    qDebug( "Group By Change Received");
    conditionBarViewModel->changeGroupBy();
    protocolSectionListViewModel->updateProtocols(this->getProtocolGroupsTwo());
}

void MainWindowViewModel::handleFilter()
{
    qDebug( "Filter Change Received");
    conditionBarViewModel->changeFilter();
}

// DEBUG PURPOSE
QList<ProtocolGroup*> MainWindowViewModel::getProtocolGroupsOne()
{
    // debug
    Protocol *one = new Protocol();
    one->setName("one");
    Protocol *two = new Protocol();
    two->setName("two");
    Protocol *three = new Protocol();
    three->setName("three");

    Aggregation *odd = new Aggregation("oddOrEven", "odd");
    Aggregation *even = new Aggregation("oddOrEven", "even");
    Aggregation *all = new Aggregation("oddOrEven", "both");

    ProtocolGroup *oddGroup = new ProtocolGroup(odd);
    oddGroup->addProtocol(one);
    oddGroup->addProtocol(three);

    ProtocolGroup *evenGroup = new ProtocolGroup(even);
    evenGroup->addProtocol(two);

    ProtocolGroup *allGroup = new ProtocolGroup(all);
    allGroup->addProtocol(one);
    allGroup->addProtocol(two);
    allGroup->addProtocol(three);

    QList<ProtocolGroup*> protocolGroup = QList<ProtocolGroup*>();
    protocolGroup.append(oddGroup);
    protocolGroup.append(evenGroup);
    protocolGroup.append(allGroup);

    return protocolGroup;
}

// DEBUG PURPOSE
QList<ProtocolGroup*> MainWindowViewModel::getProtocolGroupsTwo()
{
    // debug
    Protocol *one = new Protocol();
    one->setName("one");
    Protocol *two = new Protocol();
    two->setName("two");
    Protocol *three = new Protocol();
    three->setName("three");
    Protocol *four = new Protocol();
    four->setName("four");
    Protocol *five = new Protocol();
    five->setName("five");

    Aggregation *odd = new Aggregation("oddOrEven", "odd");
    Aggregation *even = new Aggregation("oddOrEven", "even");

    ProtocolGroup *oddGroup = new ProtocolGroup(odd);
    oddGroup->addProtocol(one);
    oddGroup->addProtocol(three);
    oddGroup->addProtocol(five);

    ProtocolGroup *evenGroup = new ProtocolGroup(even);
    evenGroup->addProtocol(two);
    evenGroup->addProtocol(four);

    QList<ProtocolGroup*> protocolGroup = QList<ProtocolGroup*>();
    protocolGroup.append(oddGroup);
    protocolGroup.append(evenGroup);

    return protocolGroup;
}
