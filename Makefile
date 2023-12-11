### VARIABLES ###
CFLAGS          = -Werror -Wextra -Wall -O3
NORM            = norminette
NAME            = fdf
SRCS_DIR        = ./src
SRCS_INC        = ./inc
SRCS            = $(SRCS_DIR)/main.c \
					$(SRCS_DIR)/check_args.c \
					$(SRCS_DIR)/extract_map_info.c \
					$(SRCS_DIR)/check_map.c \
					$(SRCS_DIR)/convert_points_to_isometric.c \
					$(SRCS_DIR)/render_image.c \
					$(SRCS_DIR)/point_operations.c \
					$(SRCS_DIR)/mlx_utils.c \
					$(SRCS_DIR)/error.c
OBJS            = $(SRCS:.c=.o)

CDEBUG          = -g3 -fsanitize=address
DEV_SRCS        = $(patsubst %/main.c, %/dev.c, $(SRCS))
DEV_OBJS        = $(DEV_SRCS:.c=.o)

### LIBRARIES ###
LIBFT_FLAGS     = -lft
LIBFT_DIR       = ./libft
LIBFT_INC       = ./libft
ifeq ($(shell uname), Linux)
	LIBMLX_DIR   = ./libmlx/linux
	LIBMLX_INC   = ./libmlx/linux
	LIBMLX_FLAGS = -lmlx -lXext -lX11 -lm -lz
else
	LIBMLX_DIR   = ./libmlx/macos
	LIBMLX_INC   = ./libmlx/macos
	LIBMLX_FLAGS = -lmlx -framework openGL -framework AppKit
endif

### RULES ###
all: $(NAME)

.c.o:
	$(CC) -I $(SRCS_INC) -I $(LIBFT_INC) -I $(LIBMLX_INC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBMLX_DIR)
	$(CC) -g3 $(OBJS) $(CFLAGS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -L $(LIBFT_DIR) -L $(LIBMLX_DIR) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBMLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

run:
	./$(NAME) $(SCENE)

norm:
	$(NORM) $(SRCS_INC) $(SRCS_DIR) $(LIBFT_DIR)

dev: CFLAGS += $(CDEBUG)
dev: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAGS) $(LIBMLX_FLAGS) -L $(LIBFT_DIR) -L $(LIBMLX_DIR) -o $(NAME)
	$(MAKE) run

valgrind:
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re
