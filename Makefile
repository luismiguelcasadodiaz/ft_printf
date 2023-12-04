#Votre Makefile ne doit pas relink. 
# That means that the Makefile should not rebuild all of the targets every time it is run.

NAME = libftprintf.a
CC = cc
CFLAGS =  -Wall -Wextra  -Werror

# From 4.4.3 The Function wildcard gnu make manual....
# Althought wildcard exparnds automaticaly in rules
# I use the wildcard function to expand wildcards in variables. 
# SRCS = $(wildcard *.c)
#
# This technique is forbidden according to 42 Norm point III.11
#
# So I must explicitly enumerate files for the project.
SRCDIR = src/
SRCS := src/ft_write_str.c \
        src/ft_write_c.c \
		src/ft_write_int_base.c \
		src/ft_write_uns_dec.c \
		src/ft_write_num_hex.c \
		src/ft_write_num_HEX.c 

BUILDIR = obj/

# Generate a list of object files by replacing .c with .o

OBJS:=$(patsubst %.c, %.o, $(SRCS))
# The default goal is the first target of the first rule in the first makefile.
# This is the reason for writtting this rule the first one
$(info $(SRCDIR))
$(info $(BUILDIR))
$(info $(SRCS))
$(info $(OBJS))

all: $(NAME)


$(NAME): $(OBJS)
	@echo "================ GATHERING ALL OBJECTS ====================="
	ar rcs $(NAME) $?


# For each c file create its object file.

%.o: %.c Makefile $(SRCDIR)libftprintf.h
	@echo "================ COMPILING ALL OBJECTS ====================="
	$(info $@)
	$(CC) $(CFLAGS) -c $< -o $@ 

# removes all generated object files
clean:
	@echo "================ REMOVING ALL OBJECTS ======================"
	rm -f $(OBJS)

# removes target file and all generated object files
fclean: clean
	@echo "================ REMOVING TARGET =========================="
	rm -f $(NAME)

# rebuild all after removing all
re: fclean all
	@echo "================ REBUILDING ==============================="
norma: $(SRCS)
	echo "================ CHECKING NORME ==========================="
	cat $(SRCS)


.PHONY: all clean fclean re

