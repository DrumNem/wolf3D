##
## Makefile for  in /home/perra_t/rendu/Piscine_C_J11
## 
## Made by tiphaine perra
## Login   <perra_t@epitech.net>
## 
## Started on  Mon Oct 20 09:31:11 2014 tiphaine perra
## Last update Thu Dec 11 15:12:49 2014 tiphaine perra
##

SRC	=	my_putchar.c \
		my_printf.c \
		my_isneg.c \
		my_put_nbr.c \
		my_swap.c \
		my_putstr.c \
		my_putnbr_long.c\
		my_strlen.c \
		my_getnbr.c \
		my_sort_int_tab.c \
		my_power_rec.c \
		my_square_root.c \
		my_is_prime.c \
		my_find_prime_sup.c \
		my_strcpy.c \
		my_strncpy.c \
		my_revstr.c \
		my_strstr.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strupcase.c \
		my_strlowcase.c \
		my_strcapitalize.c \
		my_str_isalpha.c \
		my_str_isnum.c \
		my_str_islower.c \
		my_str_isupper.c \
		my_str_isprintable.c \
		my_showstr.c \
		my_showmem.c \
		my_strcat.c \
		my_strncat.c \
		my_strlcat.c

OBJS	= $(SRC:.c=.o)

NAME	= libmy.a 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp $(NAME) ../
	mkdir -p ../include
	cp my.h ../include

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
