#ifndef MAINWINDOW_VIEWMODEL_H
#define MAINWINDOW_VIEWMODEL_H

#include <QObject>
#include "TaskBarViewModel.h"
#include "ConditionBarViewModel.h"

class MainWindowViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TaskBarViewModel *taskBarViewModel READ getTaskBarViewModel)
    Q_PROPERTY(ConditionBarViewModel *conditionBarViewModel READ getConditionBarViewModel)
public:
    explicit MainWindowViewModel(QObject *parent = 0);
    ~MainWindowViewModel();

    TaskBarViewModel *getTaskBarViewModel() const;
    ConditionBarViewModel *getConditionBarViewModel() const;
signals:

private slots:
   void handleOrderBy();
   void handleGroupBy();
   void handleFilter();

private:
   TaskBarViewModel * taskBarViewModel;
   ConditionBarViewModel * conditionBarViewModel;
};

#endif // MAINWINDOW_VIEWMODEL_H
