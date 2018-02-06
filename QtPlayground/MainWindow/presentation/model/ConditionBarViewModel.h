#ifndef CONDITIONBARVIEWMODEL_H
#define CONDITIONBARVIEWMODEL_H

#include <QObject>

class ConditionBarViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList configNames READ getConfigNames)
public:
    explicit ConditionBarViewModel(QObject *parent = nullptr);

    QStringList getConfigNames();
signals:

public slots:

private:
    QStringList configNames;
};

#endif // CONDITIONBARVIEWMODEL_H
