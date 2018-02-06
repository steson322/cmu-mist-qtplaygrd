#ifndef MAINWINDOWMODEL_H
#define MAINWINDOWMODEL_H

#include <QObject>

class MainWindowModel : public QObject
{
    Q_OBJECT

public:
    explicit MainWindowModel(QObject *parent = 0);
    ~MainWindowModel();

private:
};

#endif // MAINWINDOWMODEL_H
