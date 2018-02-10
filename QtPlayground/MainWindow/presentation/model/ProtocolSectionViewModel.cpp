#include "ProtocolSectionViewModel.h"

ProtocolSectionViewModel::ProtocolSectionViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->m_protocolViewModels = QList<ProtocolViewModel*>();
}

ProtocolSectionViewModel::ProtocolSectionViewModel(ProtocolGroup *protocolGroup, QObject *parent)
    : QAbstractListModel(parent)
{
    this->m_protocolViewModels = QList<ProtocolViewModel*>();
    for (int i = 0; i < protocolGroup->getProtocols().size(); i++)
        this->m_protocolViewModels.append(new ProtocolViewModel(protocolGroup->getProtocols().at(i)));
}

QVariant ProtocolSectionViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QVariant();
}

int ProtocolSectionViewModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return this->m_protocolViewModels.size();
}

QVariant ProtocolSectionViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QList<QVariant> list = QList<QVariant>();
    for (int i = 0; i < this->m_protocolViewModels.size(); i++)
        list.append(QVariant::fromValue(this->m_protocolViewModels.at(i)));

    return QVariant(list);
}
