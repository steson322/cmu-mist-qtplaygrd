#ifndef PROTOCOLGROUP_H
#define PROTOCOLGROUP_H

#include <QList>
#include "Protocol.h"
#include "Aggregation.h"

class ProtocolGroup
{
public:
    ProtocolGroup(Aggregation *criteria);
    ~ProtocolGroup();

    Aggregation *getCriteria() const;
    QList<Protocol*> getProtocols();
    void addProtocol(Protocol *protocol);

private:
    Aggregation *m_criteria;
    QList<Protocol*> m_protocols;
};

#endif // PROTOCOLGROUP_H
