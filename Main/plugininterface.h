#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QString>
#include <QVariant>

#include "blinksequence.h"

#define NUMLEDS 4

class PluginInterface
{
public:
    enum SettingType
    {
        TEXT,
        CHECKBOX,
        PASSWORD
    };

    struct Setting
    {
        QString name;
        SettingType type;
        QVariant value;
    };

    virtual ~PluginInterface() {}
    virtual QString name() = 0;
    virtual bool shouldBlink() = 0;
    virtual QList<Setting> settings() = 0;
    virtual void updateSetting(QString name, QVariant value) = 0;
    virtual QString version() = 0;
    //virtual BlinkSequence blinkSequence() = 0;
};

Q_DECLARE_INTERFACE(PluginInterface, "SBP.PluginInterface/0.1")

#endif // PLUGININTERFACE_H
