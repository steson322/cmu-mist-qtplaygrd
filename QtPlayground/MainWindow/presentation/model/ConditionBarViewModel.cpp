#include "ConditionBarViewModel.h"

ConditionBarViewModel::ConditionBarViewModel(QObject *parent) : QObject(parent)
{
    configNames.clear();
}


QStringList ConditionBarViewModel::getConfigNames()
{
    return configNames;
}

void ConditionBarViewModel::changeOrderBy()
{
    if (configNames.length() >= 3)
    {
        configNames.removeFirst();
    }
    configNames.append("Order By: Last Modify Date");
    emit configNamesChanged();
}

void ConditionBarViewModel::changeGroupBy()
{
    if (configNames.length() >= 3)
    {
        configNames.removeFirst();
    }
    configNames.append("Group By: Author");
    emit configNamesChanged();
}

void ConditionBarViewModel::changeFilter()
{
    if (configNames.length() >= 3)
    {
        configNames.removeFirst();
    }
    configNames.append("Filter Location: US");
    emit configNamesChanged();
}
