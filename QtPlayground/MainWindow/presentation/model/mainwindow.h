#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>

class MainWindow : public QObject
{
    Q_OBJECT

public:
    explicit MainWindow(QObject *parent = 0);
    ~MainWindow();

private:
};

#endif // MAINWINDOW_H
