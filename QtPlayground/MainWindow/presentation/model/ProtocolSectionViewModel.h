#ifndef PROTOCOLSECTIONVIEWMODEL_H
#define PROTOCOLSECTIONVIEWMODEL_H

#include <QAbstractListModel>
#include "Domain/ProtocolGroup.h"
#include "ProtocolViewModel.h"

class ProtocolSectionViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ProtocolSectionViewModel(QObject *parent = nullptr);
    ProtocolSectionViewModel(ProtocolGroup *protocolGroup, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<ProtocolViewModel *> m_protocolViewModels;
};

#endif // PROTOCOLSECTIONVIEWMODEL_H
