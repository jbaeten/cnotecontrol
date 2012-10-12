#ifndef MORSECODEPLUGIN_H
#define MORSECODEPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QSettings>
#include <QVariant>
#include <QDebug>

#include "plugininterface.h"
#include "stringtoblinksequence.h"

#define VERSION "0.1"

class BlinkSequence;
class Blink;

class MorseCodePlugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)

public:
    MorseCodePlugin();
    ~MorseCodePlugin();
    QString name();
    bool shouldBlink();
    QList<Setting> settings();
    void updateSetting(QString name, QVariant value);
    QString version();
    BlinkSequence blinkSequence();

private:
    QList<PluginInterface::Setting> m_settings;
    QSettings* m_settingsFile;
    BlinkSequence m_blinkSequence;

    void constructSettings();
    void constructBlinkSequence();
};

#endif // MORSECODEPLUGIN_H
