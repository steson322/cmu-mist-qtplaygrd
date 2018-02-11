#include "ProtocolGroup.h"

ProtocolGroup::ProtocolGroup(Aggregation *criteria)
{
    this->m_criteria = criteria;
    this->m_protocols = QList<Protocol*>();
}

ProtocolGroup::~ProtocolGroup()
{

}

void ProtocolGroup::addProtocol(Protocol *protocol)
{
    this->m_protocols.append(protocol);
}

QList<Protocol*> ProtocolGroup::getProtocols()
{
    return this->m_protocols;
}

Aggregation *ProtocolGroup::getCriteria() const
{
    return this->m_criteria;
}
