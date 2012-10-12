#ifndef BLINK_H
#define BLINK_H

#include <QList>
#include <QColor>
#include <QDebug>

class Blink
{
public:
    Blink(int numLeds);
    int numLeds();

    void setLedColor(int ledIndex, QRgb color);
    QRgb ledColor(int ledIndex);

    void setDuration(int msec);
    int duration();

    void setFadeInDuration(int msec); //set to 0 for no fade in
    int fadeInDuration();

    void setFadeOutDuration(int msec); //set to 0 for no fade out
    int fadeOutDuration();

    //!!! total blink duration will be fadeInDuration + duration + fadeOutDuration
    int totalDuration();

    QString toSerialCommand();


private:
    QList<QRgb> m_ledColorList;
    //duration variables, all in msecs
    int m_duration;
    int m_fadeInDuration;
    int m_fadeOutDuration;
};

#endif // BLINK_H
