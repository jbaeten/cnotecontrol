#ifndef GMAILPLUGIN_H
#define GMAILPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QHttp>
#include <QDebug>
#include <QSettings>
#include <QVariant>
#include "plugininterface.h"
#include "simplecrypt.h"

#define VERSION "0.1"

class BlinkSequence;
class Blink;

class GMailPlugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)

public:
    GMailPlugin();
    ~GMailPlugin();
    QString name();
    bool shouldBlink();
    QList<Setting> settings();
    void updateSetting(QString name, QVariant value);
    QString version();
    BlinkSequence blinkSequence();

private:
    QHttp m_http;
    int m_numMails;
    QList<PluginInterface::Setting> m_settings;
    SimpleCrypt m_crypto;
    QSettings* m_settingsFile;
    BlinkSequence m_blinkSequence;

    void requestGmailFeed();
    void constructSettings();
    void constructBlinkSequence();

private slots:
    void done(bool error);
};

#endif // GMAILPLUGIN_H
