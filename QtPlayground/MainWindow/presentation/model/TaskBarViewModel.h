#ifndef TASKBARVIEWMODEL_H
#define TASKBARVIEWMODEL_H

#include <QObject>

class TaskBarViewModel : public QObject
{
    Q_OBJECT
public:
    explicit TaskBarViewModel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // TASKBARVIEWMODEL_H