NAME	=	libft.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_safe_free.c\
			ft_realloc.c\
			get_next_line.c\
			get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)
# BSources are all .c files
BSRCS	=	ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c

BOBJS	=	$(BSRCS:.c=.o)

ifdef WITH_BONUS
OBJS_LIST = $(OBJS) $(BOBJS)
else
OBJS_LIST = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS_LIST)
	ar rcs $(NAME) $(OBJS_LIST)

bonus:
	make WITH_BONUS=1 all

# Removes objects
clean:
	$(RM) $(OBJS) $(BOBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
