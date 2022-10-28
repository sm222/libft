#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./include
RM		=	rm -rf

# Dir and file names
NAME	=	libft.a
SRCDIR	=	./
OBJDIR	=	bin/
DEPDIR	=	include/
SRCS	=	$(wildcard $(SRCDIR)*.c)
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))
DEP		=	$(wildcard $(DEPDIR)*.h)


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE) ar -rcs $(NAME) $(OBJS)

# Compiles source files into object files
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(OBJDIR) $(DEP)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $(OBJDIR)

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
