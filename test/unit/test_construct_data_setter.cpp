// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
#include "../../src/data/data_internal.h"
#include "data.h"
}

TEST(construct_data, normal) {
  char *map[] = {const_cast<char *>("1 2 3\n"), const_cast<char *>("4 5 6\n"),
                 const_cast<char *>("7 8 9\n"), nullptr};

  t_data *data = new t_data;
  init_cols(data, map);
  init_rows(data, map);
  init_orig_points(data, map);
  init_points(data);

  EXPECT_EQ(data->cols, 3);
  EXPECT_EQ(data->rows, 3);

  EXPECT_EQ(data->orig_points[0][0].x, 0);
  EXPECT_EQ(data->orig_points[0][1].x, 1);
  EXPECT_EQ(data->orig_points[0][2].x, 2);
  EXPECT_EQ(data->orig_points[1][0].x, 0);
  EXPECT_EQ(data->orig_points[1][1].x, 1);
  EXPECT_EQ(data->orig_points[1][2].x, 2);
  EXPECT_EQ(data->orig_points[2][0].x, 0);
  EXPECT_EQ(data->orig_points[2][1].x, 1);
  EXPECT_EQ(data->orig_points[2][2].x, 2);

  EXPECT_EQ(data->orig_points[0][0].y, 2);
  EXPECT_EQ(data->orig_points[0][1].y, 2);
  EXPECT_EQ(data->orig_points[0][2].y, 2);
  EXPECT_EQ(data->orig_points[1][0].y, 1);
  EXPECT_EQ(data->orig_points[1][1].y, 1);
  EXPECT_EQ(data->orig_points[1][2].y, 1);
  EXPECT_EQ(data->orig_points[2][0].y, 0);
  EXPECT_EQ(data->orig_points[2][1].y, 0);
  EXPECT_EQ(data->orig_points[2][2].y, 0);

  EXPECT_EQ(data->orig_points[0][0].z, 1);
  EXPECT_EQ(data->orig_points[0][1].z, 2);
  EXPECT_EQ(data->orig_points[0][2].z, 3);
  EXPECT_EQ(data->orig_points[1][0].z, 4);
  EXPECT_EQ(data->orig_points[1][1].z, 5);
  EXPECT_EQ(data->orig_points[1][2].z, 6);
  EXPECT_EQ(data->orig_points[2][0].z, 7);
  EXPECT_EQ(data->orig_points[2][1].z, 8);
  EXPECT_EQ(data->orig_points[2][2].z, 9);

  EXPECT_EQ(data->orig_points[0][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[0][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[0][2].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[1][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[1][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[1][2].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[2][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[2][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->orig_points[2][2].color, DEFAULT_COLOR_FLAG);

  EXPECT_EQ(data->points[0][0].x, -1);
  EXPECT_EQ(data->points[0][1].x, 0);
  EXPECT_EQ(data->points[0][2].x, 1);
  EXPECT_EQ(data->points[1][0].x, -1);
  EXPECT_EQ(data->points[1][1].x, 0);
  EXPECT_EQ(data->points[1][2].x, 1);
  EXPECT_EQ(data->points[2][0].x, -1);
  EXPECT_EQ(data->points[2][1].x, 0);
  EXPECT_EQ(data->points[2][2].x, 1);

  EXPECT_EQ(data->points[0][0].y, 1);
  EXPECT_EQ(data->points[0][1].y, 1);
  EXPECT_EQ(data->points[0][2].y, 1);
  EXPECT_EQ(data->points[1][0].y, 0);
  EXPECT_EQ(data->points[1][1].y, 0);
  EXPECT_EQ(data->points[1][2].y, 0);
  EXPECT_EQ(data->points[2][0].y, -1);
  EXPECT_EQ(data->points[2][1].y, -1);
  EXPECT_EQ(data->points[2][2].y, -1);

  EXPECT_EQ(data->points[0][0].z, 1);
  EXPECT_EQ(data->points[0][1].z, 2);
  EXPECT_EQ(data->points[0][2].z, 3);
  EXPECT_EQ(data->points[1][0].z, 4);
  EXPECT_EQ(data->points[1][1].z, 5);
  EXPECT_EQ(data->points[1][2].z, 6);
  EXPECT_EQ(data->points[2][0].z, 7);
  EXPECT_EQ(data->points[2][1].z, 8);
  EXPECT_EQ(data->points[2][2].z, 9);

  EXPECT_EQ(data->points[0][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[0][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[0][2].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[1][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[1][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[1][2].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[2][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[2][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[2][2].color, DEFAULT_COLOR_FLAG);
}

TEST(construct_data, withColor) {
  char *map[] = {const_cast<char *>("1,0x2 2,0x3 3,0x4\n"),
                 const_cast<char *>("4,0xAAA 5,0xFFF 6,0xFFFFFF\n"), nullptr};

  t_data *data = new t_data;
  init_cols(data, map);
  init_rows(data, map);
  init_orig_points(data, map);
  init_points(data);

  EXPECT_EQ(data->cols, 3);
  EXPECT_EQ(data->rows, 2);

  EXPECT_EQ(data->orig_points[0][0].x, 0);
  EXPECT_EQ(data->orig_points[0][1].x, 1);
  EXPECT_EQ(data->orig_points[0][2].x, 2);
  EXPECT_EQ(data->orig_points[1][0].x, 0);
  EXPECT_EQ(data->orig_points[1][1].x, 1);
  EXPECT_EQ(data->orig_points[1][2].x, 2);

  EXPECT_EQ(data->orig_points[0][0].y, 1);
  EXPECT_EQ(data->orig_points[0][1].y, 1);
  EXPECT_EQ(data->orig_points[0][2].y, 1);
  EXPECT_EQ(data->orig_points[1][0].y, 0);
  EXPECT_EQ(data->orig_points[1][1].y, 0);
  EXPECT_EQ(data->orig_points[1][2].y, 0);

  EXPECT_EQ(data->orig_points[0][0].z, 1);
  EXPECT_EQ(data->orig_points[0][1].z, 2);
  EXPECT_EQ(data->orig_points[0][2].z, 3);
  EXPECT_EQ(data->orig_points[1][0].z, 4);
  EXPECT_EQ(data->orig_points[1][1].z, 5);
  EXPECT_EQ(data->orig_points[1][2].z, 6);

  EXPECT_EQ(data->orig_points[0][0].color, 0x2);
  EXPECT_EQ(data->orig_points[0][1].color, 0x3);
  EXPECT_EQ(data->orig_points[0][2].color, 0x4);
  EXPECT_EQ(data->orig_points[1][0].color, 0xAAA);
  EXPECT_EQ(data->orig_points[1][1].color, 0xFFF);
  EXPECT_EQ(data->orig_points[1][2].color, 0xFFFFFF);

  EXPECT_EQ(data->points[0][0].x, -1);
  EXPECT_EQ(data->points[0][1].x, 0);
  EXPECT_EQ(data->points[0][2].x, 1);
  EXPECT_EQ(data->points[1][0].x, -1);
  EXPECT_EQ(data->points[1][1].x, 0);
  EXPECT_EQ(data->points[1][2].x, 1);

  EXPECT_EQ(data->points[0][0].y, 0.5);
  EXPECT_EQ(data->points[0][1].y, 0.5);
  EXPECT_EQ(data->points[0][2].y, 0.5);
  EXPECT_EQ(data->points[1][0].y, -0.5);
  EXPECT_EQ(data->points[1][1].y, -0.5);
  EXPECT_EQ(data->points[1][2].y, -0.5);

  EXPECT_EQ(data->points[0][0].z, 1);
  EXPECT_EQ(data->points[0][1].z, 2);
  EXPECT_EQ(data->points[0][2].z, 3);
  EXPECT_EQ(data->points[1][0].z, 4);
  EXPECT_EQ(data->points[1][1].z, 5);
  EXPECT_EQ(data->points[1][2].z, 6);

  EXPECT_EQ(data->points[0][0].color, 0x2);
  EXPECT_EQ(data->points[0][1].color, 0x3);
  EXPECT_EQ(data->points[0][2].color, 0x4);
  EXPECT_EQ(data->points[1][0].color, 0xAAA);
  EXPECT_EQ(data->points[1][1].color, 0xFFF);
  EXPECT_EQ(data->points[1][2].color, 0xFFFFFF);
}
