#ifndef CONDITIONBARVIEWMODEL_H
#define CONDITIONBARVIEWMODEL_H

#include <QObject>

class ConditionBarViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList configNames READ getConfigNames NOTIFY configNamesChanged)
public:
    explicit ConditionBarViewModel(QObject *parent = nullptr);

    QStringList getConfigNames();
    void changeOrderBy();
    void changeGroupBy();
    void changeFilter();
signals:
    void configNamesChanged();
public slots:

private:
    QStringList configNames;
};

#endif // CONDITIONBARVIEWMODEL_H
