CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

LIBFT_DIR=./libft/

SRCS_DIR=./srcs/

LIBFT_SRCS=$(LIBFT_DIR)ft_atoi.c\
           $(LIBFT_DIR)ft_bzero.c\
           $(LIBFT_DIR)ft_calloc.c\
           $(LIBFT_DIR)ft_isalnum.c\
           $(LIBFT_DIR)ft_isalpha.c\
           $(LIBFT_DIR)ft_isascii.c\
           $(LIBFT_DIR)ft_isdigit.c\
           $(LIBFT_DIR)ft_isprint.c\
           $(LIBFT_DIR)ft_memchr.c\
           $(LIBFT_DIR)ft_memcmp.c\
           $(LIBFT_DIR)ft_memcpy.c\
           $(LIBFT_DIR)ft_memset.c\
           $(LIBFT_DIR)ft_memmove.c\
           $(LIBFT_DIR)ft_split.c\
           $(LIBFT_DIR)ft_strdup.c\
           $(LIBFT_DIR)ft_strlcat.c\
           $(LIBFT_DIR)ft_strlcpy.c\
           $(LIBFT_DIR)ft_strlen.c\
           $(LIBFT_DIR)ft_strncmp.c\
           $(LIBFT_DIR)ft_strnstr.c\
           $(LIBFT_DIR)ft_strchr.c\
           $(LIBFT_DIR)ft_strtrim.c\
           $(LIBFT_DIR)ft_strrchr.c\
           $(LIBFT_DIR)ft_substr.c\
           $(LIBFT_DIR)ft_tolower.c\
           $(LIBFT_DIR)ft_toupper.c\
           $(LIBFT_DIR)ft_putchar_fd.c\
           $(LIBFT_DIR)ft_putstr_fd.c\
           $(LIBFT_DIR)ft_putendl_fd.c\
           $(LIBFT_DIR)ft_putnbr_fd.c\
           $(LIBFT_DIR)ft_strjoin.c\
           $(LIBFT_DIR)ft_itoa.c\
           $(LIBFT_DIR)ft_strmapi.c\
           $(LIBFT_DIR)ft_striteri.c\
           $(LIBFT_DIR)ft_malloc.c\
           $(LIBFT_DIR)ft_realloc.c\
           $(LIBFT_DIR)ft_free.c

SRCS=$(SRCS_DIR)ft_fts.c\
	 $(SRCS_DIR)ft_get_format.c\
	 $(SRCS_DIR)ft_indent.c\
	 $(SRCS_DIR)ft_print_char.c\
	 $(SRCS_DIR)ft_print_hex.c\
	 $(SRCS_DIR)ft_print_int.c\
	 $(SRCS_DIR)ft_print_percent.c\
	 $(SRCS_DIR)ft_print_ptr.c\
	 $(SRCS_DIR)ft_print_str.c\
	 $(SRCS_DIR)ft_print_uint.c\
	 $(SRCS_DIR)ft_printf.c\


LIBFT_OBJS=${LIBFT_SRCS:.c=.o}
OBJS=${SRCS:.c=.o}

NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar rc $(NAME) $?

clean: 
	$(RM) $(OBJS) $(LIBFT_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re
