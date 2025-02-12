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

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_03) {
 //%%% - Non alphabet testing
  char soundex[5];
  generateSoundex("%%%", soundex);
  ASSERT_EQ(strcmp(soundex,"0000"), 0);
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_04) {
 //Empty string is provided
  char soundex[5];
  generateSoundex("", soundex);
  ASSERT_EQ(strcmp(soundex,"0000"), 0);
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_05) {
 //Tymczak
  char soundex[5];
  generateSoundex("Tymczak", soundex);
  ASSERT_EQ(strcmp(soundex,"T520"), 0);
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_06) {
 //Alexander
  char soundex[5];
  generateSoundex("Alexander", soundex);
  ASSERT_EQ(strcmp(soundex,"A425"), 0);
}

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_07) {
 // ///
  char soundex[5];
  generateSoundex("///", soundex);
  ASSERT_EQ(strcmp(soundex,"0000"), 0);
}
