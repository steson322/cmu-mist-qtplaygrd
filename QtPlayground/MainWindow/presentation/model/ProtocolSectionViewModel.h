#ifndef PROTOCOLSECTIONVIEWMODEL_H
#define PROTOCOLSECTIONVIEWMODEL_H

#include <QAbstractListModel>
#include "Domain/ProtocolGroup.h"
#include "ProtocolViewModel.h"

class ProtocolSectionViewModel : public QAbstractListModel
{
    Q_OBJECT

    // DEBUG
    Q_PROPERTY(QString caption READ caption NOTIFY captionChanged)

public:
    explicit ProtocolSectionViewModel(QObject *parent = nullptr);
    ProtocolSectionViewModel(ProtocolGroup *protocolGroup, QObject *parent = nullptr);

    enum ProtocolRoles {
        NameRole = Qt::UserRole + 1
    };

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QHash<int, QByteArray> roleNames() const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QString caption() const;

signals:
    void captionChanged();

private:
    QList<ProtocolViewModel *> m_protocolViewModels;
    QString m_caption;
};

#endif // PROTOCOLSECTIONVIEWMODEL_H
