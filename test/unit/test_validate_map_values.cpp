// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
#include "../../src/validate/validate_internal.h"
}

TEST(validate_map_values, validValues1) {
  char *map[] = {const_cast<char *>("0 0 0 0 0\n"), nullptr};

  validate_map_values(map);
}

TEST(validate_map_values, validValues2) {
  char *map[] = {const_cast<char *>("1 2 3 4 2147483\n"), nullptr};

  validate_map_values(map);
}

TEST(validate_map_values, validValues3) {
  char *map[] = {
      const_cast<char *>("-2147488 -213647 -214646 -2147445 -214644\n"),
      nullptr};

  validate_map_values(map);
}

TEST(validate_map_values, validValues4) {
  char *map[] = {const_cast<char *>("0 0 0,0xFFFFFF 0\n"), nullptr};

  validate_map_values(map);
}

TEST(validate_map_values, invalidValues1) {
  char *map[] = {const_cast<char *>("-2147483649 0 0 0 0\n"), nullptr};

  EXPECT_EXIT(validate_map_values(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map value\n");
}

TEST(validate_map_values, invalidValues2) {
  char *map[] = {const_cast<char *>("0 0 0 0 0,0x10000000\n"), nullptr};

  EXPECT_EXIT(validate_map_values(map), ::testing::ExitedWithCode(1),
              "fdf: Invalid map value\n");
}
