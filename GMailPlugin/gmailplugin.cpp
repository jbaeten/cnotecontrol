#include "gmailplugin.h"

GMailPlugin::GMailPlugin()
{
    //connect the m_http object
    connect(&m_http, SIGNAL(done(bool)), this, SLOT(done(bool)));

    //set up the m_crypto object
    m_crypto.setKey(Q_UINT64_C(0x5b4f1d6c284ae992));

    //set up the m_settingsFile object
    m_settingsFile = new QSettings("gmailplugin.ini", QSettings::IniFormat);

    //set up the m_settings object
    constructSettings();

    //construct blink sequence
    constructBlinkSequence();

    //get the first feed
    requestGmailFeed();
}

GMailPlugin::~GMailPlugin()
{
    delete m_settingsFile;
}

QString GMailPlugin::name()
{
    return "GMail Plugin";
}

bool GMailPlugin::shouldBlink()
{
    return m_numMails > 0;
}

QList<PluginInterface::Setting> GMailPlugin::settings()
{
    return m_settings;
}

void GMailPlugin::updateSetting(QString name, QVariant value)
{
    //store the new value in memory
    for(int i = 0; i < m_settings.size(); ++i)
        if( m_settings.at(i).name == name )
            m_settings[i].value = value;

    //store it in the ini file for persistent settings
    if( name == "Password" )
    {
        QString encryptedPassword = m_crypto.encryptToString(value.toString());
        m_settingsFile->setValue("Password", encryptedPassword);
    }
    else if( name == "User" )
    {
        m_settingsFile->setValue("User", value);
    }
}

QString GMailPlugin::version()
{
    return VERSION;
}

BlinkSequence GMailPlugin::blinkSequence()
{
    return m_blinkSequence;
}

void GMailPlugin::requestGmailFeed()
{
    //get the username and password value
    QString user;
    QString password;
    for(int i = 0; i < m_settings.size(); ++i)
    {
        if( m_settings.at(i).name == "Password" )
            password = m_settings.at(i).value.toString();
        else if( m_settings.at(i).name == "User" )
            user = m_settings.at(i).value.toString();
    }

    if( user.isEmpty() || password.isEmpty() )
        return;

    //get the feed
    m_http.setHost("mail.google.com", QHttp::ConnectionModeHttps);
    m_http.setUser(user, password);
    m_http.get("/mail/feed/atom");
}

void GMailPlugin::constructSettings()
{
    Setting user;
    user.name = "User";
    user.type = PluginInterface::TEXT;
    user.value = m_settingsFile->value("User").toString();
    m_settings.append(user);
    Setting password;
    password.name = "Password";
    password.type = PluginInterface::PASSWORD;
    QString encryptedPassword = m_settingsFile->value("Password").toString();
    if( !encryptedPassword.isEmpty() )
        password.value = m_crypto.decryptToString(encryptedPassword);
    m_settings.append(password);
}

void GMailPlugin::constructBlinkSequence()
{
    //create a red fade-in fade-out blink
    Blink blink(NUMLEDS);
    for(int i = 0; i < NUMLEDS; ++i)
        blink.setLedColor(i, qRgb(255,0,0));
    blink.setFadeInDuration(333);
    blink.setDuration(333);
    blink.setFadeOutDuration(333);

    //create a pause
    Blink pause(NUMLEDS);
    pause.setDuration(1000);

    //create sequence
    m_blinkSequence.add(blink);
    m_blinkSequence.add(pause);
    m_blinkSequence.add(blink);
    m_blinkSequence.add(pause);
    m_blinkSequence.add(blink);
}

void GMailPlugin::done(bool error)
{
    if( error )
    {
        qDebug() << "Error retreiving gmail feed";
        return;
    }

    //parse data;
    QString feed = m_http.readAll();
    int posBegin = feed.lastIndexOf("<fullcount>");
    posBegin += QString("<fullcount>").length();
    int posEnd = feed.lastIndexOf("</fullcount>");
    int length = posEnd - posBegin;
    m_numMails = feed.mid(posBegin, length).toInt();
}

Q_EXPORT_PLUGIN2(gmailplugin, GMailPlugin)
