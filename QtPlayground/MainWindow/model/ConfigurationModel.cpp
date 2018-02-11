#include "ConfigurationModel.h"

ConfigurationModel::ConfigurationModel(ConfigurationType type, ConfigurationField field, QString value) : type(type), field(field), value(value)
{
}

QString ConfigurationModel::buildText()
{
    QString text;

    switch (type) {
    case ConfigurationType::ORDER_BY:
        text = text.append("Order By: ");
        break;
    case ConfigurationType::GROUP_BY:
        text = text.append("Group By: ");
        break;
    case ConfigurationType::FILTER:
        text = text.append("Filter: ");
        break;
    default:
        break;
    }

    switch (field) {
    case ConfigurationField::PROTOCOL_NAME:
        text = text.append("Protocol Name");
        break;
    case ConfigurationField::PROTOCOL_DESCRIPTION:
        text = text.append("Protocol Description");
        break;
    case ConfigurationField::AUTHOR:
        text = text.append("Author");
        break;
    case ConfigurationField::CREATION_TIME:
        text = text.append("Creation Time");
        break;
    case ConfigurationField::LAST_MODIFY_TIME:
        text = text.append("Last Modify Time");
        break;
    default:
        break;
    }

    if (value.length() > 0)
    {
        text = text.append("(");
        text = text.append(value);
        text = text.append(")");
    }
    return text;
}

ConfigurationModel::ConfigurationType ConfigurationModel::getType()
{
    return type;
}

ConfigurationModel::ConfigurationField ConfigurationModel::getField()
{
    return field;
}

QString ConfigurationModel::getValue()
{
    return value;
}
