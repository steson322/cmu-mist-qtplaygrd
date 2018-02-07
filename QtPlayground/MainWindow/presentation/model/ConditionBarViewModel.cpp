#include "ConditionBarViewModel.h"

ConditionBarViewModel::ConditionBarViewModel(QObject *parent) : QObject(parent)
{
    configNames.clear();
    configNames.append("Group By: Author");
    configNames.append("Sort By: Last Modify Date");
    configNames.append("Filter Location: US");
}


QStringList ConditionBarViewModel::getConfigNames()
{
    return configNames;
}
