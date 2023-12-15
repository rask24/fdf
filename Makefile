CFLAGS			= -Werror -Wextra -Wall -O3
NORM			= norminette

NAME			= fdf

SRC_DIR			= ./src
BUILD_DIR		= ./build
INC_DIR			= ./inc
SRC				= $(SRC_DIR)/main.c \
					$(SRC_DIR)/check_args.c \
					$(SRC_DIR)/extract_map_info.c \
					$(SRC_DIR)/check_map.c \
					$(SRC_DIR)/plot_line.c \
					$(SRC_DIR)/keydown_events.c \
					$(SRC_DIR)/convert_points_to_isometric.c \
					$(SRC_DIR)/render_image.c \
					$(SRC_DIR)/handle_events.c \
					$(SRC_DIR)/point_operations.c \
					$(SRC_DIR)/mlx_utils.c \
					$(SRC_DIR)/error.c
OBJ				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
DEP				= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(SRC))
DEPFLAGS		= -MMD -MP

LIBFT_FLAGS		= -lft
LIBFT_DIR		= ./libft
ifeq ($(shell uname), Linux)
	LIBMLX_DIR   = ./libmlx/linux
	LIBMLX_FLAGS = -lmlx -lXext -lX11 -lm -lz
else
	LIBMLX_DIR   = ./libmlx/macos
	LIBMLX_FLAGS = -lmlx -framework openGL -framework AppKit
endif

INCLUDE = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(LIBMLX_DIR)

GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m
RESET	=	\033[0m

all: title $(NAME)

$(NAME): $(OBJ)
	@echo "\ncomplied [$(GREEN)✔︎$(RESET)]"
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(LIBMLX_DIR)
	@$(CC) $(OBJ) $(CFLAGS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -L $(LIBFT_DIR) -L $(LIBMLX_DIR) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@
	@printf "$(GREEN).$(RESET)"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@$(RM) $(OBJ) $(DEP)
	@echo "$(RED)fdf: delete objs deps$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)fdf: delete fdf$(RESET)"

re: fclean all

norm:
	$(NORM) $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

title:
	@echo "$(BLUE)fdf$(RESET)"

.PHONY: all clean fclean re

-include $(DEP)
