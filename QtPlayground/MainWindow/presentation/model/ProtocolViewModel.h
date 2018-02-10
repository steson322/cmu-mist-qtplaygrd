#ifndef PROTOCOLVIEWMODEL_H
#define PROTOCOLVIEWMODEL_H

#include <QObject>

#include "Domain/Protocol.h"

class ProtocolViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit ProtocolViewModel(QObject *parent = nullptr);
    ProtocolViewModel(const Protocol *protocol);
    ~ProtocolViewModel();

    QString name();
    void setName(const QString newName);

signals:
    void nameChanged();

public slots:

private:
    QString m_name;
};

#endif // PROTOCOLVIEWMODEL_H
