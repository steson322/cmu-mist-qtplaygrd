#include "MainWindowViewModel.h"

MainWindowViewModel::MainWindowViewModel(QObject * parent) :
    QObject(parent),
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

void MainWindowViewModel::handleOrderBy()
{
    qDebug( "Order By Change Received");
    conditionBarViewModel->changeOrderBy();
}

void MainWindowViewModel::handleGroupBy()
{
    qDebug( "Group By Change Received");
    conditionBarViewModel->changeGroupBy();
}

void MainWindowViewModel::handleFilter()
{
    qDebug( "Filter Change Received");
    conditionBarViewModel->changeFilter();
}
