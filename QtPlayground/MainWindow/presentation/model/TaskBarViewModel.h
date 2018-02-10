#ifndef TASKBARVIEWMODEL_H
#define TASKBARVIEWMODEL_H

#include <QObject>

class TaskBarViewModel : public QObject
{
    Q_OBJECT
public:
    explicit TaskBarViewModel(QObject *parent = nullptr);

    Q_INVOKABLE void addNewProtocol();
    Q_INVOKABLE void orderBy();
    Q_INVOKABLE void groupBy();
    Q_INVOKABLE void filter();
signals:
   void orderByChanged();
   void groupByChanged();
   void filterChanged();
public slots:
private:
};

#endif // TASKBARVIEWMODEL_H
