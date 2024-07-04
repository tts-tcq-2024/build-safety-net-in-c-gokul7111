#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

static char charList[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'};

char IsAlphabet(char c)
{
    return ((c >= 'A') && (c <= 'Z'));
}

char getSoundexCode(char c) {
    c = IsAlphabet(c)*toupper(c) + (!IsAlphabet(c)*'A');
    return charList[c - 'A'];
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';

   for (int i = 1, sIndex = 1; name[i] != '\0' && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
