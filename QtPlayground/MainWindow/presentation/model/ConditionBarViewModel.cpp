#include "ConditionBarViewModel.h"

const QString ORDER_BY = "order_by";
const QString GROUP_BY = "group_by";
const QString FILTER = "filter";

ConditionBarViewModel::ConditionBarViewModel(QObject *parent) : QObject(parent)
{
}

void ConditionBarViewModel::remove(QString key)
{
    qDebug("Request to Remove");
    configurationMap.remove(key);
    emit configurationChanged();
}

void ConditionBarViewModel::removeAll()
{
    qDebug("Request to Remove All");
    configurationMap.clear();
    emit configurationChanged();
}

QStringList ConditionBarViewModel::getConfigurationNames()
{
    QStringList *list = new QStringList(configurationMap.keys());
    return *list;
}

void ConditionBarViewModel::changeOrderBy()
{
    ConfigurationModel *configuration = new ConfigurationModel(
                ConfigurationModel::ConfigurationType::ORDER_BY,
                ConfigurationModel::ConfigurationField::LAST_MODIFY_TIME);
    QString text = configuration->buildText();
    if (configurationMap.contains(text))
    {
        return;
    }
    qDebug(qPrintable(text));
    configurationMap.insert(text, *configuration);
    emit configurationChanged();
}

void ConditionBarViewModel::changeGroupBy()
{
    ConfigurationModel *configuration = new ConfigurationModel(
                ConfigurationModel::ConfigurationType::GROUP_BY,
                ConfigurationModel::ConfigurationField::AUTHOR);
    QString text = configuration->buildText();
    if (configurationMap.contains(GROUP_BY))
    {
        return;
    }
    qDebug(qPrintable(text));
    configurationMap.insert(text, *configuration);
    emit configurationChanged();
}

void ConditionBarViewModel::changeFilter()
{
    ConfigurationModel *configuration = new ConfigurationModel(
                ConfigurationModel::ConfigurationType::FILTER,
                ConfigurationModel::ConfigurationField::PROTOCOL_NAME,
                "Some*");
    QString text = configuration->buildText();
    if (configurationMap.contains(FILTER))
    {
        return;
    }
    qDebug(qPrintable(text));
    configurationMap.insert(text, *configuration);
    emit configurationChanged();
}
