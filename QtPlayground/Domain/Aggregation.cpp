#include "Aggregation.h"

Aggregation::Aggregation()
{
    this->key = QString("");
    this->value = QString("");
}

Aggregation::Aggregation(const QString key, const QString value)
{
    this->key = key;
    this->value = value;
}

Aggregation::~Aggregation()
{

}

const QString Aggregation::getKey()
{
    return this->key;
}

const QString Aggregation::getValue()
{
    return this->value;
}
