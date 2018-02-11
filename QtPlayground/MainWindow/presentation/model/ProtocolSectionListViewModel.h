#ifndef PROTOCOLSECTIONLISTVIEWMODEL_H
#define PROTOCOLSECTIONLISTVIEWMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "Domain/ProtocolGroup.h"
#include "ProtocolSectionViewModel.h"

class ProtocolSectionListViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProtocolSectionListViewModel(QObject *parent = nullptr);
    ProtocolSectionListViewModel(QList<ProtocolGroup*> protocolGroups, QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Data
    void updateProtocols(QList<ProtocolGroup*> protocolGroups);
private:
    QList<QVariant> m_protocolSections;
};

#endif // PROTOCOLSECTIONLISTVIEWMODEL_H
