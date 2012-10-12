#include "stringtoblinksequence.h"

StringToBlinkSequence::StringToBlinkSequence()
{
}

BlinkSequence StringToBlinkSequence::convert(QString string)
{
    BlinkSequence result;

    if( string.isEmpty() )
        return result;

    Blink dit(NUMLEDS);
    dit.setDuration(UNIT);
    for(int i = 0; i < NUMLEDS; ++i)
        dit.setLedColor(i, qRgb(255,255,255));

    Blink dah(NUMLEDS);
    dah.setDuration(3*UNIT);
    for(int i = 0; i < NUMLEDS; ++i)
        dah.setLedColor(i, qRgb(255,255,255));

    Blink elementGap(NUMLEDS);
    elementGap.setDuration(UNIT);
    for(int i = 0; i < NUMLEDS; ++i)
        elementGap.setLedColor(i, qRgb(0,0,0));

    Blink letterGap(NUMLEDS);
    letterGap.setDuration(3*UNIT);
    for(int i = 0; i < NUMLEDS; ++i)
        letterGap.setLedColor(i, qRgb(0,0,0));

    Blink wordGap(NUMLEDS);
    wordGap.setDuration(7*UNIT);
    for(int i = 0; i < NUMLEDS; ++i)
        wordGap.setLedColor(i, qRgb(0,0,0));

    string = string.toLower().trimmed();

    for(int i = 0; i < string.length(); ++i)
    {
        switch( string.at(i).toAscii() )
        {
        case 'a': // .-
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'b': // -...
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'c': // -.-.
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'd': // -..
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'e': // .
            result.add(dit);
            break;
        case 'f': // ..-.
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'g': // --.
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'h': // ....
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'i': // ..
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'j': // .---
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'k': // -.-
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'l': // .-..
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'm': // --
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'n': // -.
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'o': // ---
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'p': // .--.
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case 'q': // --.-
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'r': // .-.
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case 's': // ...
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case 't': // -
            result.add(dah);
            break;
        case 'u': // ..-
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'v': // ...-
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'w': // .--
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'x': // -..-
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'y': // -.--
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case 'z': // --..
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case '1': // .----
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case '2': // ..---
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case '3': // ...--
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case '4': // ....-
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dah);
            break;
        case '5': // .....
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case '6': // -....
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            break;
        case '7': // --...
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case '8': // ---..
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            result.add(elementGap);
            result.add(dit);
            break;
        case '9': // ----.
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dit);
            break;
        case '0': // -----
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            result.add(elementGap);
            result.add(dah);
            break;
        case ' ':
            result.add(wordGap);
        }

        if( i < string.length()-1 && string.at(i) != ' ' )
            result.add(letterGap);
    }

    return result;
}
