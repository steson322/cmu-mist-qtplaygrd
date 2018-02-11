#ifndef CONFIGURATIONMODEL_H
#define CONFIGURATIONMODEL_H

#include <QObject>

class ConfigurationModel
{
public:
    enum ConfigurationType
    {
        ORDER_BY,
        GROUP_BY,
        FILTER,
    };

    enum ConfigurationField
    {
        PROTOCOL_NAME,
        PROTOCOL_DESCRIPTION,
        AUTHOR,
        CREATION_TIME,
        LAST_MODIFY_TIME,
    };

    ConfigurationModel(ConfigurationType type, ConfigurationField field, QString value = "");

    // TODO: use string for now, it should use more specific types
    ConfigurationType getType();
    ConfigurationField getField();
    QString getValue();
    QString buildText();
signals:

private:
    ConfigurationType type;
    ConfigurationField field;
    QString value;
};

#endif //CONFIGURATIONMODEL_H
