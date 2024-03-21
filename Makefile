# shell
SHELL		= /bin/bash
UNAME		= $(shell uname)

# executable and archive files
NAME		= fdf

# compiler options
CFLAGS		= -Werror -Wextra -Wall
PROD_FLAGS	= -O3
DEV_FLAGS	= -O0 -g -fsanitize=address,undefined,integer
DEP_FLAGS	= -MMD -MP
INCLUDE		= -I $(INC_DIR) -I $(LIBFT_DIR)/include -I $(LIBMLX_DIR)
LD_FLAGS	= -L $(LIBFT_DIR) -L $(LIBMLX_DIR)
LD_LIBS		= -lft

# directories
SRC_DIR		= src
BUILD_DIR	= build
INC_DIR		= include
LIBFT_DIR	= libft

ifeq ($(UNAME), Linux)
	LIBMLX_DIR	= ./libmlx/linux
	LD_LIBS		+= -lmlx -lXext -lX11 -lm -lz
else ifeq ($(UNAME), Darwin)
	LIBMLX_DIR	= ./libmlx/macos
	LD_LIBS		+= -lmlx -framework openGL -framework AppKit
endif

# files
SRC				= $(SRC_DIR)/main.c \
					$(SRC_DIR)/validate/validate_args.c \
					$(SRC_DIR)/validate/validate_map.c \
					$(SRC_DIR)/init/extract_map_info.c \
					$(SRC_DIR)/init/convert_points_to_isometric.c \
					$(SRC_DIR)/events/handle_events.c \
					$(SRC_DIR)/events/keydown_events.c \
					$(SRC_DIR)/events/exit_window.c \
					$(SRC_DIR)/point_operations/rotate_points_x.c \
					$(SRC_DIR)/point_operations/rotate_points_y.c \
					$(SRC_DIR)/point_operations/rotate_points_z.c \
					$(SRC_DIR)/point_operations/translate_points.c \
					$(SRC_DIR)/point_operations/scale_points.c \
					$(SRC_DIR)/utils/mlx_utils.c \
					$(SRC_DIR)/utils/exit_with_error.c \
					$(SRC_DIR)/render_image/render_image.c \
					$(SRC_DIR)/render_image/plot_line.c \
					$(SRC_DIR)/render_image/color_gradient.c \
					$(SRC_DIR)/render_image/calc_ratio.c \
					$(SRC_DIR)/render_image/frac_utils.c \
					$(SRC_DIR)/render_image/plot_point_to_image.c
OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRC))

# colors
RESET			= \033[0m
ORANGE			= \033[0;33m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[1;92m
YELLOW			= \033[1;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

# rules
.PHONY: all
all: title $(NAME)

$(NAME): $(OBJ)
	@echo "\ncomplied [$(GREEN)✔︎$(RESET)]"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(LIBMLX_DIR)
	@if [ $(UNAME) = "Darwin" ]; then cp $(LIBMLX_DIR)/libmlx.dylib .; fi
	@$(CC) $(OBJ) $(CFLAGS) $(LD_LIBS) $(LD_FLAGS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEP_FLAGS) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

-include $(DEP)

.PHONY: clean
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@if [ $(UNAME) = "Darwin" ]; then $(RM) libmlx.dylib ; fi
	@$(RM) $(OBJ) $(DEP)
	@echo "$(RED)fdf: delete objs deps$(RESET)"

.PHONY: fclean
fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)fdf: delete fdf$(RESET)"

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	norminette $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

.PHONY: title
title:
	@echo "$(BLUE)fdf$(RESET)"
