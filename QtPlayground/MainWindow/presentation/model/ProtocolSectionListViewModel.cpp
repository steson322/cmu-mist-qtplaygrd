#include "ProtocolSectionListViewModel.h"

ProtocolSectionListViewModel::ProtocolSectionListViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->m_protocolSections = QList<QVariant>();
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
        QVariant v = QVariant::fromValue(new ProtocolSectionViewModel(protocolGroups.at(i), this));
        this->m_protocolSections.append(v);
    }
    qDebug(" new protocol group received, size = %d", this->m_protocolSections.size());

    this->endResetModel();
    //emit layoutChanged();
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
    qDebug("pre-called data for %d", index.row());
    if (!index.isValid())
        return QVariant();

    qDebug("called data for %d", index.row());
    return QVariant(this->m_protocolSections);
}
