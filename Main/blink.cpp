#include "blink.h"

Blink::Blink(int numLeds)
{
    //initialize list of led colors
    for(int i = 0; i < numLeds; ++i)
        m_ledColorList.append(qRgb(0,0,0));
    //initialize other vars
    m_duration = 0;
    m_fadeInDuration = 0;
    m_fadeOutDuration = 0;
}

int Blink::numLeds()
{
    return m_ledColorList.size();
}

void Blink::setLedColor(int ledIndex, QRgb color)
{
    if( ledIndex < 0 || ledIndex >= m_ledColorList.size() )
    {
        qDebug() << "setLedColor() ledIndex out of bounds";
        return;
    }

    m_ledColorList.replace(ledIndex, color);
}

QRgb Blink::ledColor(int ledIndex)
{
    if( ledIndex < 0 || ledIndex >= m_ledColorList.size() )
    {
        qDebug() << "ledColor() ledIndex out of bounds";
        return 0;
    }

    return m_ledColorList.at(ledIndex);
}

void Blink::setDuration(int msec)
{
    m_duration = msec;
}

int Blink::duration()
{
    return m_duration;
}

void Blink::setFadeInDuration(int msec)
{
    m_fadeInDuration = msec;
}

int Blink::fadeInDuration()
{
    return m_fadeInDuration;
}

void Blink::setFadeOutDuration(int msec)
{
    m_fadeOutDuration = msec;
}

int Blink::fadeOutDuration()
{
    return m_fadeOutDuration;
}

int Blink::totalDuration()
{
    return m_fadeInDuration + m_duration + m_fadeOutDuration;
}

QString Blink::toSerialCommand()
{
    QString serialCommand;
    for(int i = 0; i < numLeds(); ++i)
    {
        serialCommand.append(QString::number(qRed(m_ledColorList.at(i))) + ";"
                             + QString::number(qGreen(m_ledColorList.at(i))) + ";"
                             + QString::number(qBlue(m_ledColorList.at(i))) + ";"
                             + QString::number(m_fadeInDuration) + ";"
                             + QString::number(m_duration) + ";"
                             + QString::number(m_fadeOutDuration) + ";");
    }
    serialCommand.replace(serialCommand.length()-1, 1, "\0");
    qDebug() << serialCommand;
    return serialCommand;
}
