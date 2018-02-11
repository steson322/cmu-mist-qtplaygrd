#ifndef MAINWINDOW_VIEWMODEL_H
#define MAINWINDOW_VIEWMODEL_H

#include <QObject>
#include "TaskBarViewModel.h"
#include "ConditionBarViewModel.h"
#include "ProtocolSectionListViewModel.h"
#include "../../model/ConfigurationModel.h"

class MainWindowViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TaskBarViewModel *taskBarViewModel READ getTaskBarViewModel NOTIFY taskBarViewModelChanged)
    Q_PROPERTY(ConditionBarViewModel *conditionBarViewModel READ getConditionBarViewModel NOTIFY conditionBarViewModelChanged)
    Q_PROPERTY(ProtocolSectionListViewModel *protocolSectionListViewModel READ getProtocolSectionListViewModel NOTIFY protocolSectionListViewModelChanged)
public:
    explicit MainWindowViewModel(QObject *parent = 0);
    ~MainWindowViewModel();

    TaskBarViewModel *getTaskBarViewModel() const;
    ConditionBarViewModel *getConditionBarViewModel() const;
    ProtocolSectionListViewModel *getProtocolSectionListViewModel() const;
signals:
    void taskBarViewModelChanged();
    void conditionBarViewModelChanged();
    void protocolSectionListViewModelChanged();
private slots:
   void handleOrderBy();
   void handleGroupBy();
   void handleFilter();
   void handleRemoveConfiguration(QString key);
   void handleRemoveAllConfigurations();

private:
   TaskBarViewModel * taskBarViewModel;
   ConditionBarViewModel * conditionBarViewModel;
   ProtocolSectionListViewModel *protocolSectionListViewModel;

   // Key: Configuration label, Value: Configuration object
   QMap<QString, ConfigurationModel> configurationMap;

   QList<ProtocolGroup*> getProtocolGroupsOne();
   QList<ProtocolGroup*> getProtocolGroupsTwo();
};

#endif // MAINWINDOW_VIEWMODEL_H
