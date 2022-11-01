#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re
# 'HIDE = @' will hide all terminal output from Make
HIDE =


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f

# Output file name
NAME	=	libft.a

# Sources are all .c files
SRCDIR	=	src/
SRCS	=	src/ft_atoi.c\
			src/ft_bzero.c\
			src/ft_calloc.c\
			src/ft_isalnum.c\
			src/ft_isalpha.c\
			src/ft_isascii.c\
			src/ft_isdigit.c\
			src/ft_isprint.c\
			src/ft_itoa.c\
			src/ft_memchr.c\
			src/ft_memcmp.c\
			src/ft_memcpy.c\
			src/ft_memmove.c\
			src/ft_memset.c\
			src/ft_putchar_fd.c\
			src/ft_putend_fd.c\
			src/ft_putnbr_fd.c\
			src/ft_putstr_fd.c\
			src/ft_split.c\
			src/ft_strchr.c\
			src/ft_strdup.c\
			src/ft_striteri.c\
			src/ft_strjoin.c\
			src/ft_strlcat.c\
			src/ft_strlcpy.c\
			src/ft_strlen.c\
			src/ft_strmapi.c\
			src/ft_strncmp.c\
			src/ft_strnstr.c\
			src/ft_strrchr.c\
			src/ft_strtrim.c\
			src/ft_substr.c\
			src/ft_tolower.c\
			src/ft_toupper.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))


# BSources are all .c files
BSRCS	=	src/text.c

# BObjects are all .o files
BOBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(BSRCS))

# Includes are all .h files
INCDIR	=	include/
INC		=	$(wildcard $(INCDIR)*.h)


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE) ar -rcs $@ $^

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $@

bonus: $(NAME) $(BOBJS)
	$(HIDE) ar -rs $(NAME) $(BOBJS)

$(BOBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS) $(BOBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
