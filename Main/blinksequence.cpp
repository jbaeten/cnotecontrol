#include "blinksequence.h"

BlinkSequence::BlinkSequence()
{
}

void BlinkSequence::add(Blink blink)
{
    m_blinkSequence.append(blink);
}

void BlinkSequence::remove(int index)
{
    m_blinkSequence.removeAt(index);
}

void BlinkSequence::insertBefore(int index, Blink blink)
{
    m_blinkSequence.insert(index, blink);
}

int BlinkSequence::count()
{
    return m_blinkSequence.size();
}

Blink BlinkSequence::at(int index) const
{
    return m_blinkSequence.at(index);
}
