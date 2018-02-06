#ifndef MAINWINDOW_VIEWMODEL_H
#define MAINWINDOW_VIEWMODEL_H

#include <QObject>

class MainWindowViewModel : public QObject
{
    Q_OBJECT

public:
    explicit MainWindowViewModel(QObject *parent = 0);
    ~MainWindowViewModel();

private:
};

#endif // MAINWINDOW_VIEWMODEL_H
