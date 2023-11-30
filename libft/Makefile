NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror -I .
ARFLAGS	=	cr

SRCS	=	$(addprefix memory/,\
				ft_bzero.c \
				ft_calloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
			)

SRCS	+=	$(addprefix output/, \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
			)

SRCS	+=	$(addprefix type/, \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_tolower.c \
				ft_toupper.c \
			)

SRCS	+=	$(addprefix string/, \
				ft_atoi.c \
				ft_itoa.c \
				ft_free_strs.c \
				ft_split.c \
				ft_strchr.c \
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

SRCS	+=	$(addprefix list/, \
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

SRCS	+=	$(addprefix ft_printf/, \
				ft_printf.c \
				nbr_utils.c \
				conversion_router.c \
				parse_spec.c \
				print_integer.c \
				print_string.c \
			)

SRCS	+=	$(addprefix get_next_line/, \
				get_next_line.c \
				get_next_line_utils.c \
			)

SRCS	+=	$(addprefix file/, \
				file_to_line_array.c \
			)

SRCS	+=	$(addprefix integer/, \
				ft_max.c \
				ft_min.c \
				ft_chmax.c \
				ft_chmin.c \
				ft_swap.c \
			)

OBJS = $(SRCS:.c=.o)

GTESTDIR		=	gtest
GTEST			=	$(GTESTDIR)/gtest $(GTESTDIR)/googletest-release-1.11.0
TESTDIR			=	test
TEST_COMPILE	=	clang++ -std=c++11 \
					$(TESTDIR)/gtest.cpp $(GTESTDIR)/googletest-release-1.11.0/googletest/src/gtest_main.cc \
					$(GTESTDIR)/gtest/gtest-all.cc -I $(GTESTDIR) -I . -L . -l ft -lpthread -o tester

GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m
RESET	=	\033[0m

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

norm:
	norminette ft_printf get_next_line list memory string type file libft.h

test: $(GTEST)
	@echo "$(BLUE)test$(RESET)"
	@$(TEST_COMPILE)
	@./tester # --gtest_filter=Vector.other

$(GTEST):
	@curl -OL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz
	@tar -xvzf release-1.11.0.tar.gz googletest-release-1.11.0
	@$(RM) release-1.11.0.tar.gz
	@python3 googletest-release-1.11.0/googletest/scripts/fuse_gtest_files.py $(GTESTDIR)
	@mv googletest-release-1.11.0 $(GTESTDIR)

title:
	@echo "$(BLUE)libft$(RESET)"

env:
	@echo $(PWD)

.PHONY: all bonus clean fclean re norm test title
