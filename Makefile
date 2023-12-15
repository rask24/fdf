CFLAGS			= -Werror -Wextra -Wall -O3
NORM			= norminette

NAME			= fdf

SRC_DIR			= ./src
INC_DIR			= ./inc
SRC				= $(SRC_DIR)/main.c \
					$(SRC_DIR)/check_args.c \
					$(SRC_DIR)/extract_map_info.c \
					$(SRC_DIR)/check_map.c \
					$(SRC_DIR)/convert_points_to_isometric.c \
					$(SRC_DIR)/render_image.c \
					$(SRC_DIR)/handle_events.c \
					$(SRC_DIR)/point_operations.c \
					$(SRC_DIR)/mlx_utils.c \
					$(SRC_DIR)/error.c
OBJ				= $(SRC:.c=.o)
DEP				= $(SRC:.c=.d)
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

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) $(DEPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBMLX_DIR)
	$(CC) $(OBJ) $(CFLAGS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -L $(LIBFT_DIR) -L $(LIBMLX_DIR) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

norm:
	$(NORM) $(INC_DIR) $(SRC_DIR) $(LIBFT_DIR)

.PHONY: all clean fclean re

-include $(DEP)
