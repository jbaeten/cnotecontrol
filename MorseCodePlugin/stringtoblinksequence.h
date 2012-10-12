#ifndef STRINGTOBLINKSEQUENCE_H
#define STRINGTOBLINKSEQUENCE_H

#include "blink.h"
#include "blinksequence.h"
#include "plugininterface.h"
#include <QColor>

#define UNIT 200

class StringToBlinkSequence
{
public:
    StringToBlinkSequence();

    static BlinkSequence convert(QString string);
};

#endif // STRINGTOBLINKSEQUENCE_H
