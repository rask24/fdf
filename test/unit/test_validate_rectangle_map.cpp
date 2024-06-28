// Copyright 2024, reasuke

#include <string.h>

#include "gtest/gtest.h"

extern "C" {
#include "../../src/validate/validate_internal.h"
}

TEST(validate_rectangle_map, validMap1) {
  char *map[] = {const_cast<char *>("1 2 3\n"), const_cast<char *>("4 5 6\n"),
                 const_cast<char *>("7 8 9\n"), NULL};

  EXPECT_NO_FATAL_FAILURE(validate_rectangle_map(map));
}

TEST(validate_rectangle_map, validMap2) {
  char *map[] = {const_cast<char *>("1 2 3\n"), const_cast<char *>("4 5 6\n"),
                 const_cast<char *>("7 8 9"), NULL};

  EXPECT_NO_FATAL_FAILURE(validate_rectangle_map(map));
}

TEST(validate_rectangle_map, validMap3) {
  char *map[] = {const_cast<char *>("1\t2\t3\n"),
                 const_cast<char *>("4\t5\t6\n"),
                 const_cast<char *>("7\t8\t9\t\n"), NULL};

  EXPECT_NO_FATAL_FAILURE(validate_rectangle_map(map));
}

TEST(validate_rectangle_map, validMap4) {
  char *map[] = {const_cast<char *>("        1,one 2 3     \n"),
                 const_cast<char *>("\t\t\t\t4,four 5 6\t  \n"),
                 const_cast<char *>("        7 8 9,nine    \n"),
                 const_cast<char *>("\t  \t  10 11,eleven 12"), NULL};

  EXPECT_NO_FATAL_FAILURE(validate_rectangle_map(map));
}

TEST(validate_rectangle_map, InvalidMap1) {
  char *map[] = {const_cast<char *>("1 2 3"), const_cast<char *>("4 5 6 7"),
                 const_cast<char *>("8 9"), NULL};

  EXPECT_EXIT(validate_rectangle_map(map), ::testing::ExitedWithCode(1),
              "fdf: Map is not a rectangle\n");
}

TEST(validate_rectangle_map, InvalidMap2) {
  char *map[] = {const_cast<char *>("1 2 3"), const_cast<char *>("4 5 6"),
                 const_cast<char *>("7 8"), NULL};

  EXPECT_EXIT(validate_rectangle_map(map), ::testing::ExitedWithCode(1),
              "fdf: Map is not a rectangle\n");
}

TEST(validate_rectangle_map, InvalidMap3) {
  char *map[] = {const_cast<char *>("1 2 3"), const_cast<char *>("4 5 6"),
                 const_cast<char *>("7 8 9 10"), NULL};

  EXPECT_EXIT(validate_rectangle_map(map), ::testing::ExitedWithCode(1),
              "fdf: Map is not a rectangle\n");
}

TEST(validate_rectangle_map, InvalidMap4) {
  char *map[] = {const_cast<char *>("0"), NULL};

  EXPECT_EXIT(validate_rectangle_map(map), ::testing::ExitedWithCode(1),
              "fdf: Map is not a rectangle\n");
}
