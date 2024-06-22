// Copyright 2024, reasuke

#include "gtest/gtest.h"

extern "C" {
#include <math.h>

#include "../../src/data/data_internal.h"
#include "data.h"
}

TEST(apply_operation, translate) {
  t_data *data = (t_data *)malloc(sizeof(t_data));
  t_point **points = (t_point **)malloc(sizeof(t_point *) * 3);
  points[0] = (t_point *)malloc(sizeof(t_point) * 3);
  points[1] = (t_point *)malloc(sizeof(t_point) * 3);
  points[2] = (t_point *)malloc(sizeof(t_point) * 3);

  points[0][0] = (t_point){0, 2, 1, DEFAULT_COLOR_FLAG};
  points[0][1] = (t_point){1, 2, 2, DEFAULT_COLOR_FLAG};
  points[0][2] = (t_point){2, 2, 3, DEFAULT_COLOR_FLAG};
  points[1][0] = (t_point){0, 1, 4, DEFAULT_COLOR_FLAG};
  points[1][1] = (t_point){1, 1, 5, DEFAULT_COLOR_FLAG};
  points[1][2] = (t_point){2, 1, 6, DEFAULT_COLOR_FLAG};
  points[2][0] = (t_point){0, 0, 7, DEFAULT_COLOR_FLAG};
  points[2][1] = (t_point){1, 0, 8, DEFAULT_COLOR_FLAG};
  points[2][2] = (t_point){2, 0, 9, DEFAULT_COLOR_FLAG};

  data->cols = 3;
  data->rows = 3;
  data->points = points;

  apply_operation(data, translate_x, 1.0);
  apply_operation(data, translate_y, -1.0);

  EXPECT_EQ(data->points[0][0].x, 1);
  EXPECT_EQ(data->points[0][1].x, 2);
  EXPECT_EQ(data->points[0][2].x, 3);
  EXPECT_EQ(data->points[1][0].x, 1);
  EXPECT_EQ(data->points[1][1].x, 2);
  EXPECT_EQ(data->points[1][2].x, 3);
  EXPECT_EQ(data->points[2][0].x, 1);
  EXPECT_EQ(data->points[2][1].x, 2);
  EXPECT_EQ(data->points[2][2].x, 3);

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
}

TEST(apply_operation, scale) {
  t_data *data = (t_data *)malloc(sizeof(t_data));
  t_point **points = (t_point **)malloc(sizeof(t_point *) * 3);
  points[0] = (t_point *)malloc(sizeof(t_point) * 3);
  points[1] = (t_point *)malloc(sizeof(t_point) * 3);
  points[2] = (t_point *)malloc(sizeof(t_point) * 3);

  points[0][0] = (t_point){0, 2, 1, DEFAULT_COLOR_FLAG};
  points[0][1] = (t_point){1, 2, 2, DEFAULT_COLOR_FLAG};
  points[0][2] = (t_point){2, 2, 3, DEFAULT_COLOR_FLAG};
  points[1][0] = (t_point){0, 1, 4, DEFAULT_COLOR_FLAG};
  points[1][1] = (t_point){1, 1, 5, DEFAULT_COLOR_FLAG};
  points[1][2] = (t_point){2, 1, 6, DEFAULT_COLOR_FLAG};
  points[2][0] = (t_point){0, 0, 7, DEFAULT_COLOR_FLAG};
  points[2][1] = (t_point){1, 0, 8, DEFAULT_COLOR_FLAG};
  points[2][2] = (t_point){2, 0, 9, DEFAULT_COLOR_FLAG};

  data->cols = 3;
  data->rows = 3;
  data->points = points;

  apply_operation(data, scale_x, 2.0);
  apply_operation(data, scale_y, 3.0);

  EXPECT_EQ(data->points[0][0].x, 0);
  EXPECT_EQ(data->points[0][1].x, 2);
  EXPECT_EQ(data->points[0][2].x, 4);
  EXPECT_EQ(data->points[1][0].x, 0);
  EXPECT_EQ(data->points[1][1].x, 2);
  EXPECT_EQ(data->points[1][2].x, 4);
  EXPECT_EQ(data->points[2][0].x, 0);
  EXPECT_EQ(data->points[2][1].x, 2);
  EXPECT_EQ(data->points[2][2].x, 4);

  EXPECT_EQ(data->points[0][0].y, 6);
  EXPECT_EQ(data->points[0][1].y, 6);
  EXPECT_EQ(data->points[0][2].y, 6);
  EXPECT_EQ(data->points[1][0].y, 3);
  EXPECT_EQ(data->points[1][1].y, 3);
  EXPECT_EQ(data->points[1][2].y, 3);
  EXPECT_EQ(data->points[2][0].y, 0);
  EXPECT_EQ(data->points[2][1].y, 0);
  EXPECT_EQ(data->points[2][2].y, 0);

  EXPECT_EQ(data->points[0][0].z, 1);
  EXPECT_EQ(data->points[0][1].z, 2);
  EXPECT_EQ(data->points[0][2].z, 3);
  EXPECT_EQ(data->points[1][0].z, 4);
  EXPECT_EQ(data->points[1][1].z, 5);
  EXPECT_EQ(data->points[1][2].z, 6);
  EXPECT_EQ(data->points[2][0].z, 7);
  EXPECT_EQ(data->points[2][1].z, 8);
  EXPECT_EQ(data->points[2][2].z, 9);
}

TEST(apply_operation, rotate) {
  t_data *data = (t_data *)malloc(sizeof(t_data));
  t_point **points = (t_point **)malloc(sizeof(t_point *) * 3);
  points[0] = (t_point *)malloc(sizeof(t_point) * 3);
  points[1] = (t_point *)malloc(sizeof(t_point) * 3);
  points[2] = (t_point *)malloc(sizeof(t_point) * 3);

  points[0][0] = (t_point){0, 2, 1, DEFAULT_COLOR_FLAG};
  points[0][1] = (t_point){1, 2, 2, DEFAULT_COLOR_FLAG};
  points[0][2] = (t_point){2, 2, 3, DEFAULT_COLOR_FLAG};
  points[1][0] = (t_point){0, 1, 4, DEFAULT_COLOR_FLAG};
  points[1][1] = (t_point){1, 1, 5, DEFAULT_COLOR_FLAG};
  points[1][2] = (t_point){2, 1, 6, DEFAULT_COLOR_FLAG};
  points[2][0] = (t_point){0, 0, 7, DEFAULT_COLOR_FLAG};
  points[2][1] = (t_point){1, 0, 8, DEFAULT_COLOR_FLAG};
  points[2][2] = (t_point){2, 0, 9, DEFAULT_COLOR_FLAG};

  data->cols = 3;
  data->rows = 3;
  data->points = points;

  apply_operation(data, rotate_z, M_PI_2);

  double epsilon = 1e-6;

  EXPECT_NEAR(data->points[0][0].x, -2, epsilon);
  EXPECT_NEAR(data->points[0][0].y, 0, epsilon);

  EXPECT_NEAR(data->points[0][1].x, -2, epsilon);
  EXPECT_NEAR(data->points[0][1].y, 1, epsilon);

  EXPECT_NEAR(data->points[0][2].x, -2, epsilon);
  EXPECT_NEAR(data->points[0][2].y, 2, epsilon);

  EXPECT_NEAR(data->points[1][0].x, -1, epsilon);
  EXPECT_NEAR(data->points[1][0].y, 0, epsilon);

  EXPECT_NEAR(data->points[1][1].x, -1, epsilon);
  EXPECT_NEAR(data->points[1][1].y, 1, epsilon);

  EXPECT_NEAR(data->points[1][2].x, -1, epsilon);
  EXPECT_NEAR(data->points[1][2].y, 2, epsilon);

  EXPECT_NEAR(data->points[2][0].x, 0, epsilon);
  EXPECT_NEAR(data->points[2][0].y, 0, epsilon);

  EXPECT_NEAR(data->points[2][1].x, 0, epsilon);
  EXPECT_NEAR(data->points[2][1].y, 1, epsilon);

  EXPECT_NEAR(data->points[2][2].x, 0, epsilon);
  EXPECT_NEAR(data->points[2][2].y, 2, epsilon);
}
