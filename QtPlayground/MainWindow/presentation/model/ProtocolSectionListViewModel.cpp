#include "ProtocolSectionListViewModel.h"

ProtocolSectionListViewModel::ProtocolSectionListViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->m_protocolSections = QList<ProtocolSectionViewModel*>();
}

ProtocolSectionListViewModel::ProtocolSectionListViewModel(QList<ProtocolGroup *> protocolGroups, QObject *parent)
    : QAbstractListModel(parent)
{
    this->updateProtocols(protocolGroups);
}

void ProtocolSectionListViewModel::updateProtocols(QList<ProtocolGroup *> protocolGroups)
{
    this->beginResetModel();
    this->m_protocolSections.clear();

    for (int i = 0; i < protocolGroups.size(); i++)
    {
        ProtocolSectionViewModel *newSection = new ProtocolSectionViewModel(protocolGroups.at(i), this);
        this->m_protocolSections.append(newSection);
    }
    this->endResetModel();
}

QHash<int, QByteArray> ProtocolSectionListViewModel::roleNames() const
{
    QHash<int, QByteArray> hash;
    hash[CaptionRole] = "caption";
    hash[ProtocolRole] = "protocols";
    return hash;
}

int ProtocolSectionListViewModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return this->m_protocolSections.size();
}

QVariant ProtocolSectionListViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() > rowCount() - 1)
        return QVariant();

    if (role == CaptionRole)
        return QVariant(this->m_protocolSections.at(index.row())->caption());
    else if (role == ProtocolRole)
        return QVariant::fromValue(this->m_protocolSections.at(index.row()));
    else
        return QVariant();
}
