#include "ProtocolSectionViewModel.h"

ProtocolSectionViewModel::ProtocolSectionViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    this->m_protocolViewModels = QList<ProtocolViewModel*>();
    this->m_caption = "         World";
}

ProtocolSectionViewModel::ProtocolSectionViewModel(ProtocolGroup *protocolGroup, QObject *parent)
    : QAbstractListModel(parent)
{
    this->m_protocolViewModels = QList<ProtocolViewModel*>();
    for (int i = 0; i < protocolGroup->getProtocols().size(); i++)
        this->m_protocolViewModels.append(new ProtocolViewModel(protocolGroup->getProtocols().at(i)));
    this->m_caption = "         World";
}

QString ProtocolSectionViewModel::caption() const
{
    return m_caption;
}

QVariant ProtocolSectionViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> ProtocolSectionViewModel::roleNames() const
{
    QHash<int, QByteArray> hash;
    hash[NameRole] = "name";
    return hash;
}

int ProtocolSectionViewModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    qDebug("protocol sections rows: %d", this->m_protocolViewModels.size());

    return this->m_protocolViewModels.size();
}

QVariant ProtocolSectionViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < 0 || index.row() > rowCount() - 1)
        return QVariant();

    if (role == NameRole)
    {
        qDebug("---> returning name for protocol: " + this->m_protocolViewModels.at(index.row())->name().toLatin1());
        return this->m_protocolViewModels.at(index.row())->name();
    }
    else
        return QVariant();
}
