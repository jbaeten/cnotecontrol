#include "morsecodeplugin.h"

MorseCodePlugin::MorseCodePlugin()
{
    m_settingsFile = new QSettings("morsecodeplugin.ini", QSettings::IniFormat);
    constructSettings();
    constructBlinkSequence();
}

MorseCodePlugin::~MorseCodePlugin()
{
    delete m_settingsFile;
}

QString MorseCodePlugin::name()
{
    return "Morse Code Plugin";
}

bool MorseCodePlugin::shouldBlink()
{
    return false;
}

QList<PluginInterface::Setting> MorseCodePlugin::settings()
{
    return m_settings;
}

void MorseCodePlugin::updateSetting(QString name, QVariant value)
{
    if( name == "Morse code string" )
    {
        m_settings[0].value = value;
        m_settingsFile->setValue("morsecodestring", value);
        constructBlinkSequence();
    }
}

QString MorseCodePlugin::version()
{
    return VERSION;
}

BlinkSequence MorseCodePlugin::blinkSequence()
{
    return m_blinkSequence;
}

void MorseCodePlugin::constructSettings()
{
    Setting morsecodestring;
    morsecodestring.name = "Morse code string";
    morsecodestring.type = PluginInterface::TEXT;
    morsecodestring.value = m_settingsFile->value("morsecodestring", "SOS");
    m_settings.append(morsecodestring);
}

void MorseCodePlugin::constructBlinkSequence()
{
    qDebug() << "voor construct";
    m_blinkSequence = StringToBlinkSequence::convert(m_settings.at(0).value.toString());
    qDebug() << "na construct";
}

Q_EXPORT_PLUGIN2(morsecodeplugin, MorseCodePlugin)
