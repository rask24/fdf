NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .
ARFLAGS = cr

SRCS = $(addprefix memory/,\
			ft_bzero.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
		)

SRCS += $(addprefix output/, \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
		)

SRCS += $(addprefix type/, \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
		)

SRCS += $(addprefix string/, \
			ft_atoi.c \
			ft_itoa.c \
			ft_free_strs.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtol.c \
			ft_strtrim.c \
		)

SRCS += $(addprefix list/, \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
		)

SRCS += $(addprefix ft_printf/, \
			ft_printf.c \
			nbr_utils.c \
			conversion_router.c \
			parse_spec.c \
			print_integer.c \
			print_string.c \
		)

SRCS += $(addprefix get_next_line/, \
			get_next_line.c \
			get_next_line_utils.c \
		)

SRCS += $(addprefix file/, \
			file_to_line_array.c \
		)

SRCS += $(addprefix integer/, \
			ft_swap.c \
		)

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m

all: title $(NAME)
	@echo "complied [$(GREEN)✔︎$(RESET)]"

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^
	@printf "\n"

%.o: %.c
	@printf "$(GREEN).$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)delete objs$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)delete libft$(RESET)"
	@$(RM) $(NAME)

re: fclean all

title:
	@echo "$(BLUE)libft$(RESET)"

.PHONY: all bonus clean fclean re title
