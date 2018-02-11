#ifndef CONDITIONBARVIEWMODEL_H
#define CONDITIONBARVIEWMODEL_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include "../../model/ConfigurationModel.h"

class ConditionBarViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList configurationNames READ getConfigurationNames NOTIFY configurationChanged)
public:
    explicit ConditionBarViewModel(QObject *parent = nullptr);

    Q_INVOKABLE void remove(const QString id);
    Q_INVOKABLE void removeAll();

    QStringList getConfigurationNames();
    void changeOrderBy();
    void changeGroupBy();
    void changeFilter();
signals:
    void configurationChanged();
public slots:

private:
    // Key: Configuration label, Value: Configuration object
    QMap<QString, ConfigurationModel> configurationMap;
};

#endif // CONDITIONBARVIEWMODEL_H
