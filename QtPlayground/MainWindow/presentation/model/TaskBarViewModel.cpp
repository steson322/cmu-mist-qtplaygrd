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
    emit orderByChanged();
}

void TaskBarViewModel::groupBy()
{
    emit groupByChanged();
}

void TaskBarViewModel::filter()
{
    emit filterChanged();
}
