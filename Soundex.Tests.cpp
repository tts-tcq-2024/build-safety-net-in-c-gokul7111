#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_01) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_EQ(strcmp(soundex,"A200"), 0);
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_02) {
 //GOKUL
  char soundex[5];
  generateSoundex("gokul", soundex);
  ASSERT_EQ(strcmp(soundex,"G240"), 0);
}
