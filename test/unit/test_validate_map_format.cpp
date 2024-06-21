// Copyright 2024, reasuke

#include <string>

#include "gtest/gtest.h"

extern "C" {
#include "../../src/validate/validate_internal.h"
}

TEST(validate_map_format, validFormat1) {
  char *map[] = {const_cast<char *>("0 0 0 0"), nullptr};
  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormat2) {
  char *map[] = {const_cast<char *>("1 2 3 4\n"), nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormat3) {
  char *map[] = {const_cast<char *>("1\t2\t3\t4\n"), nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormat4) {
  char *map[] = {const_cast<char *>(" \t\t1 \t 2 \t 3 \t 4 \t\t \n"), nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormat5) {
  char *map[] = {const_cast<char *>("1 2 3 4\n"),
                 const_cast<char *>("5 6 7 8\n"),
                 const_cast<char *>("9 10 11 12\n"), nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormatWithHex1) {
  char *map[] = {const_cast<char *>("0 0 0,0x0 0\n"), nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormatWithHex2) {
  char *map[] = {const_cast<char *>("1 2 3,0x4 5\n"), nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, validFormatWithHex3) {
  char *map[] = {
      const_cast<char *>("0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 8,0xFFFFFF "
                         "8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0\n"),
      const_cast<char *>("0 0 0 0 0 1 2 3 4 5 6 7 8,0xFFFFFF 9,0xFFFFFF "
                         "8,0xFFFFFF 7 6 5 4 3 2 1 0 0 0 0 0\n"),
      nullptr};

  EXPECT_NO_FATAL_FAILURE(validate_map_format(map));
}

TEST(validate_map_format, invalidFormat1) {
  char *map[] = {const_cast<char *>("0 0 abc 0 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormat2) {
  char *map[] = {const_cast<char *>("0 0 123abd 0\n"),
                 const_cast<char *>("0 0 0 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormat3) {
  char *map[] = {const_cast<char *>("0 0 abc123 0 \n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex1) {
  char *map[] = {const_cast<char *>("0 0, 0 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex2) {
  char *map[] = {const_cast<char *>("0 0 0 0,x0 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex3) {
  char *map[] = {const_cast<char *>("0 0 0 0,0x 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex4) {
  char *map[] = {const_cast<char *>("0 0 0,FFF 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex5) {
  char *map[] = {const_cast<char *>("0 0 0,0xFGA 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex6) {
  char *map[] = {const_cast<char *>("0 0 ,0x123 0\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}

TEST(validate_map_format, invalidFormatWithHex7) {
  char *map[] = {const_cast<char *>("0 0 0,0x\n"), nullptr};

  EXPECT_EXIT(validate_map_format(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map format\n");
}
