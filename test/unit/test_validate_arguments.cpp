// Copyright 2024, reasuke.

#include <string>

#include "gtest/gtest.h"

extern "C" {
#include "validate.h"
}

// ./fdf test.fdf
TEST(validate_arguments, validNormalPath) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"), const_cast<char *>("test.fdf")};

  EXPECT_NO_FATAL_FAILURE(validate_arguments(argc, argv));
}

// ./fdf ./maps/test.fdf
TEST(validate_arguments, validRelativePath) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"),
                  const_cast<char *>("./maps/test.fdf")};

  EXPECT_NO_FATAL_FAILURE(validate_arguments(argc, argv));
}

// ./fdf test\@\#\$.fdf
TEST(validate_arguments, validSpecialChars) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"),
                  const_cast<char *>("test@#$.fdf")};
  EXPECT_NO_FATAL_FAILURE(validate_arguments(argc, argv));
}

// ./fdf /usr/local/maps/test.fdf
TEST(validate_arguments, validAbsolutePath) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"),
                  const_cast<char *>("/usr/local/maps/test.fdf")};
  EXPECT_NO_FATAL_FAILURE(validate_arguments(argc, argv));
}

// ./fdf
TEST(validate_arguments, onlyExecutable) {
  int argc = 1;
  char *argv[] = {const_cast<char *>("./fdf")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid number of arguments\n");
}

// ./fdf test.fdf dummy
TEST(validate_arguments, tooManyArguments) {
  int argc = 3;
  char *argv[] = {const_cast<char *>("./fdf"), const_cast<char *>("test.fdf"),
                  const_cast<char *>("dummy")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid number of arguments\n");
}

// ./fdf test.txt
TEST(validate_arguments, invalidFileFormat) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"), const_cast<char *>("test.txt")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid file format\n");
}

// ./fdf test.fdf.txt
TEST(validate_arguments, invalidFileFormat2) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"),
                  const_cast<char *>("test.fdf.txt")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid file format\n");
}

// ./fdf test
TEST(validate_arguments, invalidFileFormat3) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"), const_cast<char *>("test")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid file format\n");
}

// ./fdf test.fdf.
TEST(validate_arguments, invalidFileFormat4) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"), const_cast<char *>("test.fdf.")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid file format\n");
}

// ./fdf .fdf
TEST(validate_arguments, invalidFileFormat5) {
  int argc = 2;
  char *argv[] = {const_cast<char *>("./fdf"), const_cast<char *>(".fdf")};

  EXPECT_EXIT(validate_arguments(argc, argv), ::testing::ExitedWithCode(1),
              "fdf: Invalid file format\n");
}
