#include "TaskBarViewModel.h"

TaskBarViewModel::TaskBarViewModel(QObject *parent) : QObject(parent)
{
}

void TaskBarViewModel::addNewProtocol()
{
    qDebug( "Add New Protocol Clicked" );
}

void TaskBarViewModel::orderBy()
{
    qDebug( "Order By Clicked" );
    emit orderByChanged();
}

void TaskBarViewModel::groupBy()
{
    qDebug( "Group By Clicked" );
    emit groupByChanged();
}

void TaskBarViewModel::filter()
{
    qDebug( "Filter Clicked" );
    emit filterChanged();
}
