#include "ProtocolViewModel.h"

ProtocolViewModel::ProtocolViewModel(QObject *parent) : QObject(parent)
{
    this->m_name = QString("");
}

ProtocolViewModel::ProtocolViewModel(const Protocol *protocol) : QObject(nullptr) {
    this->m_name = protocol->getName();
}

ProtocolViewModel::~ProtocolViewModel()
{

}

QString ProtocolViewModel::name()
{
    return this->m_name;
}

void ProtocolViewModel::setName(const QString newName)
{
    if (this->m_name != newName)
    {
        this->m_name = newName;
        emit nameChanged();
    }
}
