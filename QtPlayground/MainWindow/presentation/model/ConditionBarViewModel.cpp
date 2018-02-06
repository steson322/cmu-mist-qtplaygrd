#include "ConditionBarViewModel.h"

ConditionBarViewModel::ConditionBarViewModel(QObject *parent) : QObject(parent)
{
    configNames.clear();
    configNames.append("1");
    configNames.append("2");
    configNames.append("3");
}


QStringList ConditionBarViewModel::getConfigNames()
{
    return configNames;
}
