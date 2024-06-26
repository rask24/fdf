// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
#include "../../src/data/data_internal.h"
#include "data.h"
#include "mlx_conf.h"
}

static double _calc_xy_scale(t_data *data) {
  double x_scale;
  double y_scale;

  x_scale = (double)(WIN_WIDTH - 2 * WIN_MARGIN) / data->cols;
  y_scale = (double)(WIN_HEIGHT - 2 * WIN_MARGIN) / data->rows;
  if (x_scale < y_scale)
    return (x_scale);
  else
    return (y_scale);
}

static double _calc_z_scale(t_data *data, double xy_scale) {
  double z_range;

  z_range = data->orig_z_max - data->orig_z_min;
  if (z_range * xy_scale < Z_RANGE_THRESHOLD) return (xy_scale / 2.0);
  return (Z_RANGE_THRESHOLD / z_range);
}

TEST(construct_data, normal) {
  char *map[] = {const_cast<char *>("1 2 3\n"), const_cast<char *>("4 5 6\n"),
                 const_cast<char *>("7 8 9\n"), nullptr};

  t_data *data = new t_data;
  init_cols(data, map);
  init_rows(data, map);
  init_orig_points(data, map);
  init_orig_z_min_max(data);
  init_points(data);

  double xy_scale = _calc_xy_scale(data);
  double z_scale = _calc_z_scale(data, xy_scale);

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

  EXPECT_EQ(data->orig_points[0][0].y, 0);
  EXPECT_EQ(data->orig_points[0][1].y, 0);
  EXPECT_EQ(data->orig_points[0][2].y, 0);
  EXPECT_EQ(data->orig_points[1][0].y, 1);
  EXPECT_EQ(data->orig_points[1][1].y, 1);
  EXPECT_EQ(data->orig_points[1][2].y, 1);
  EXPECT_EQ(data->orig_points[2][0].y, 2);
  EXPECT_EQ(data->orig_points[2][1].y, 2);
  EXPECT_EQ(data->orig_points[2][2].y, 2);

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

  EXPECT_EQ(data->points[0][0].x, -1 * xy_scale);
  EXPECT_EQ(data->points[0][1].x, 0 * xy_scale);
  EXPECT_EQ(data->points[0][2].x, 1 * xy_scale);
  EXPECT_EQ(data->points[1][0].x, -1 * xy_scale);
  EXPECT_EQ(data->points[1][1].x, 0 * xy_scale);
  EXPECT_EQ(data->points[1][2].x, 1 * xy_scale);
  EXPECT_EQ(data->points[2][0].x, -1 * xy_scale);
  EXPECT_EQ(data->points[2][1].x, 0 * xy_scale);
  EXPECT_EQ(data->points[2][2].x, 1 * xy_scale);

  EXPECT_EQ(data->points[0][0].y, -1 * xy_scale);
  EXPECT_EQ(data->points[0][1].y, -1 * xy_scale);
  EXPECT_EQ(data->points[0][2].y, -1 * xy_scale);
  EXPECT_EQ(data->points[1][0].y, 0 * xy_scale);
  EXPECT_EQ(data->points[1][1].y, 0 * xy_scale);
  EXPECT_EQ(data->points[1][2].y, 0 * xy_scale);
  EXPECT_EQ(data->points[2][0].y, 1 * xy_scale);
  EXPECT_EQ(data->points[2][1].y, 1 * xy_scale);
  EXPECT_EQ(data->points[2][2].y, 1 * xy_scale);

  EXPECT_EQ(data->points[0][0].z, 1 * z_scale);
  EXPECT_EQ(data->points[0][1].z, 2 * z_scale);
  EXPECT_EQ(data->points[0][2].z, 3 * z_scale);
  EXPECT_EQ(data->points[1][0].z, 4 * z_scale);
  EXPECT_EQ(data->points[1][1].z, 5 * z_scale);
  EXPECT_EQ(data->points[1][2].z, 6 * z_scale);
  EXPECT_EQ(data->points[2][0].z, 7 * z_scale);
  EXPECT_EQ(data->points[2][1].z, 8 * z_scale);
  EXPECT_EQ(data->points[2][2].z, 9 * z_scale);

  EXPECT_EQ(data->points[0][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[0][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[0][2].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[1][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[1][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[1][2].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[2][0].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[2][1].color, DEFAULT_COLOR_FLAG);
  EXPECT_EQ(data->points[2][2].color, DEFAULT_COLOR_FLAG);

  EXPECT_EQ(data->orig_z_min, 1);
  EXPECT_EQ(data->orig_z_max, 9);
}

TEST(construct_data, withColor) {
  char *map[] = {const_cast<char *>("1,0x2 2,0x3 3,0x4\n"),
                 const_cast<char *>("4,0xAAA 5,0xFFF 6,0xFFFFFF\n"), nullptr};

  t_data *data = new t_data;
  init_cols(data, map);
  init_rows(data, map);
  init_orig_points(data, map);
  init_orig_z_min_max(data);
  init_points(data);

  double xy_scale = _calc_xy_scale(data);
  double z_scale = _calc_z_scale(data, xy_scale);

  EXPECT_EQ(data->cols, 3);
  EXPECT_EQ(data->rows, 2);

  EXPECT_EQ(data->orig_points[0][0].x, 0);
  EXPECT_EQ(data->orig_points[0][1].x, 1);
  EXPECT_EQ(data->orig_points[0][2].x, 2);
  EXPECT_EQ(data->orig_points[1][0].x, 0);
  EXPECT_EQ(data->orig_points[1][1].x, 1);
  EXPECT_EQ(data->orig_points[1][2].x, 2);

  EXPECT_EQ(data->orig_points[0][0].y, 0);
  EXPECT_EQ(data->orig_points[0][1].y, 0);
  EXPECT_EQ(data->orig_points[0][2].y, 0);
  EXPECT_EQ(data->orig_points[1][0].y, 1);
  EXPECT_EQ(data->orig_points[1][1].y, 1);
  EXPECT_EQ(data->orig_points[1][2].y, 1);

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

  EXPECT_EQ(data->points[0][0].x, -1 * xy_scale);
  EXPECT_EQ(data->points[0][1].x, 0 * xy_scale);
  EXPECT_EQ(data->points[0][2].x, 1 * xy_scale);
  EXPECT_EQ(data->points[1][0].x, -1 * xy_scale);
  EXPECT_EQ(data->points[1][1].x, 0 * xy_scale);
  EXPECT_EQ(data->points[1][2].x, 1 * xy_scale);

  EXPECT_EQ(data->points[0][0].y, -0.5 * xy_scale);
  EXPECT_EQ(data->points[0][1].y, -0.5 * xy_scale);
  EXPECT_EQ(data->points[0][2].y, -0.5 * xy_scale);
  EXPECT_EQ(data->points[1][0].y, 0.5 * xy_scale);
  EXPECT_EQ(data->points[1][1].y, 0.5 * xy_scale);
  EXPECT_EQ(data->points[1][2].y, 0.5 * xy_scale);

  EXPECT_EQ(data->points[0][0].z, 1 * z_scale);
  EXPECT_EQ(data->points[0][1].z, 2 * z_scale);
  EXPECT_EQ(data->points[0][2].z, 3 * z_scale);
  EXPECT_EQ(data->points[1][0].z, 4 * z_scale);
  EXPECT_EQ(data->points[1][1].z, 5 * z_scale);
  EXPECT_EQ(data->points[1][2].z, 6 * z_scale);

  EXPECT_EQ(data->points[0][0].color, 0x2);
  EXPECT_EQ(data->points[0][1].color, 0x3);
  EXPECT_EQ(data->points[0][2].color, 0x4);
  EXPECT_EQ(data->points[1][0].color, 0xAAA);
  EXPECT_EQ(data->points[1][1].color, 0xFFF);
  EXPECT_EQ(data->points[1][2].color, 0xFFFFFF);

  EXPECT_EQ(data->orig_z_min, 1);
  EXPECT_EQ(data->orig_z_max, 6);
}
