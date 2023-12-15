MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)

NAME=libmlx.dylib

INC=-I.

GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

all: title $(NAME)
	@echo "complied [$(GREEN)✔︎$(RESET)]"

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@printf "$(GREEN).$(RESET)"
	@swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@printf "\n"

%.o: %.swift
	@printf "$(GREEN).$(RESET)"
	@swiftc $(INC) -parse-as-library -c $< -o $@

%.o: %.c
	@printf "$(GREEN).$(RESET)"
	@$(CC) -c $< -o $@

%.swiftmodule: %.swift
	@printf "$(GREEN).$(RESET)"
	@swiftc $(INC) -parse-as-library -c $< -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	@echo "$(RED)libmlx: delete libmlx$(RESET)"
	@$(RM) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~

fclean: clean
	@echo "$(RED)libmlx: delete libmlx$(RESET)"
	@$(RM) $(NAME)

re: clean all

title:
	@echo "$(BLUE)libmlx$(RESET)"

.PHONY: all clean fclean re title
