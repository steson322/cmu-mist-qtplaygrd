#include "Protocol.h"

Protocol::Protocol()
{
    this->m_name = "";
}

QString Protocol::getName() const
{
    return this->m_name;
}

void Protocol::setName(const QString &value)
{
    this->m_name = value;
}
