#ifndef AGGREGATION_H
#define AGGREGATION_H

#include <QString>

class Aggregation
{
public:
    Aggregation();
    Aggregation(const QString key, const QString value);
    ~Aggregation();

    const QString getKey();
    const QString getValue();

private:
    QString key;
    QString value;

};

#endif // AGGREGATION_H
