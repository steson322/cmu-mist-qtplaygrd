#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QString>

class Protocol
{
public:
    Protocol();
    ~Protocol();

    QString getName() const;
    void setName(const QString &value);

private:
    QString m_name;
};

#endif // PROTOCOL_H
