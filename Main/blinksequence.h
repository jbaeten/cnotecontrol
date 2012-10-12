#ifndef BLINKSEQUENCE_H
#define BLINKSEQUENCE_H

#include <QList>

#include "blink.h"

class BlinkSequence
{
public:
    BlinkSequence();

    void add(Blink blink);
    void remove(int index);
    void insertBefore(int index, Blink blink);
    int count();
    Blink at(int index) const;

private:
    QList<Blink> m_blinkSequence;
};

#endif // BLINKSEQUENCE_H
