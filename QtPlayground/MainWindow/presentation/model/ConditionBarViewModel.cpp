#include "ConditionBarViewModel.h"

ConditionBarViewModel::ConditionBarViewModel(QObject *parent) : QObject(parent)
{
}

void ConditionBarViewModel::remove(QString key)
{
    configurationNames.remove(key);
    emit configurationChanged();
    emit configurationRemoved(key);
}

void ConditionBarViewModel::removeAll()
{
    configurationNames.clear();
    emit configurationChanged();
    emit allConfigurationsRemoved();
}

QStringList ConditionBarViewModel::getConfigurationNames()
{
    QStringList *list = new QStringList(configurationNames.toList());
    return *list;
}

void ConditionBarViewModel::add(QString key)
{
    configurationNames.insert(key);
    emit configurationChanged();
}

