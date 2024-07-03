#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

static char charList[26] = {'0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'};

char getSoundexCode(char c) {
    c = toupper(c);
    boolean IsAlphabet = (c >= 'A') && (c <= 'Z');
    if(IsAlphabet)
    {
        return charList[c - 'A'];
    }
    else
    {
        return '0';
    }
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    soundex[1] = '0';
    soundex[2] = '0';
    soundex[3] = '0';
    soundex[4] = '\0';
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = code;
        }
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
