#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

static char charList[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'};

bool IsCodeValid(char currChar, char prevCode)
{
    return (currChar != '0' && currChar != prevCode);
}

bool IsAlphabet(char c)
{
    return ((c >= 'A') && (c <= 'Z'));
}

char getSoundexCode(char c) {
    char code = int(IsAlphabet(toupper(c))*toupper(c) + (!IsAlphabet(toupper(c))*'A'));
    return charList[code - 'A'];
}

bool countinueInteration(char c, int index)
{
     return (c != '\0' && index < 4);
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = int(IsAlphabet(toupper(name[0]))*toupper(name[0]) + (!IsAlphabet(toupper(name[0]))*'0'));
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';

   for (int i = 1, sIndex = 1; countinueInteration(name[i], sIndex); i++) {
        char code = getSoundexCode(name[i]);
        if (IsCodeValid(code, soundex[sIndex - 1] )) {
            soundex[sIndex++] = code;
        }
    }
}

#endif // SOUNDEX_H
