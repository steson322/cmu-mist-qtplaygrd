#ifndef CONDITIONBARVIEWMODEL_H
#define CONDITIONBARVIEWMODEL_H

#include <QObject>
#include <QSet>
#include <QVariant>

class ConditionBarViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList configurationNames READ getConfigurationNames NOTIFY configurationChanged)
public:
    explicit ConditionBarViewModel(QObject *parent = nullptr);

    Q_INVOKABLE void remove(const QString key);
    Q_INVOKABLE void removeAll();

    QStringList getConfigurationNames();
    void add(QString key);
signals:
    void configurationChanged();
    void configurationRemoved(const QString key);
    void allConfigurationsRemoved();
public slots:

private:
    QSet<QString> configurationNames;
};

#endif // CONDITIONBARVIEWMODEL_H
