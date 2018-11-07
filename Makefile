NAME = libftprintf.a

CC = clang

CFLAGS = #-Wall -Werror -Wextra -g3 -fsanitize=address

LFLAGS = -Llibft -lft

DIR = srcs

OBJDIR = objs

LIB = libft/libft.a

SRCS = ft_printf.c	ft_putbuf.c	ft_vfprintf.c	ft_flags.c	\
	   ft_fwidth.c		ft_precis.c	ft_length.c	ft_ltoa.c		ft_ident.c	\
	   ft_putwchar.c

SRC = $(addprefix $(DIR)/,$(SRCS))

SRCS_LIB =															\
	ft_abs.c		ft_atoi.c		ft_bzero.c		ft_isalnum.c	\
	ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c	\
	ft_isspace.c	ft_itoa.c		ft_labs.c		ft_lstadd.c		\
	ft_lstdel.c		ft_lstdelone.c	ft_lstiter.c	ft_lstlen.c		\
	ft_lstmap.c		ft_lstnew.c		ft_memalloc.c	ft_memccpy.c	\
	ft_memchr.c		ft_memcmp.c		ft_memcpy.c		ft_memdel.c		\
	ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c	\
	ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	\
	ft_putstr.c		ft_putstr_fd.c	ft_strcat.c		ft_strchr.c		\
	ft_strclr.c		ft_strcmp.c		ft_strcpy.c		ft_strdel.c		\
	ft_strdup.c		ft_strequ.c		ft_striter.c	ft_striteri.c	\
	ft_strjoin.c	ft_strlcat.c	ft_strlen.c		ft_strmap.c		\
	ft_strmapi.c	ft_strncat.c	ft_strncmp.c	ft_strncpy.c	\
	ft_strnequ.c	ft_strnew.c		ft_strnstr.c	ft_strrchr.c	\
	ft_strrev.c		ft_strsplit.c	ft_strstr.c		ft_strsub.c		\
	ft_strtrim.c	ft_tolower.c	ft_toupper.c	get_next_line.c	\
	ft_getnline.c	ft_freetab.c	ft_itoa_base.c

OBJ = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

OBJ_LIB = $(addprefix $(OBJDIR)/,$(SRCS_LIB:.c=.o))

HEADERS = -I includes -I libft/includes

all: $(NAME)

$(LIB):
	@make -C libft
	@mkdir -p $(OBJDIR)
	@cd objs && ar -x ../libft/libft.a

$(NAME): $(LIB) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJ_LIB)
	@printf "\r$$(tput setaf 2)$@$$(tput sgr0)\n"

$(OBJDIR)/%.o: $(DIR)/%.c Makefile
	@printf "$$(tput setaf 8)$<"
	@$(CC) -o $@ -c $< $(HEADERS) $(CFLAGS) && \
	printf "$$(tput setaf 2)$<$$(tput sgr0)\r$$(tput el)"

clean:
	@rm -rf $(OBJDIR)
	@make -s -C libft clean

fclean: clean
	@rm -f $(NAME) test
	@make -s -C libft fclean

re: fclean all

test: $(NAME)
	@$(CC) $(DIR)/*.c $(HEADERS) $(LIB) -o $@
	@printf "\r$$(tput setaf 2)$@$$(tput sgr0)\n"

.PHONY: all, clean, fclean, re, test
