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
    this->m_protocolSections = QList<ProtocolSectionViewModel*>();
    for (int i = 0; i < protocolGroups.size(); i++)
        this->m_protocolSections.append(new ProtocolSectionViewModel(protocolGroups.at(i), this));
    qDebug(" new protocol group received, size = %d", this->m_protocolSections.size());
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

    QList<QVariant> list = QList<QVariant>();
    for (int i = 0; i < this->m_protocolSections.size(); i++)
        list.append(QVariant::fromValue(this->m_protocolSections.at(i)));

    return QVariant(list);
}
