##
## Makefile for  in /home/perra_t/rendu/CPE_2014_Pushswap
## 
## Made by tiphaine perra
## Login   <perra_t@epitech.net>
## 
## Started on  Tue Dec  2 13:48:43 2014 tiphaine perra
## Last update Fri Dec 19 18:03:02 2014 tiphaine perra
##

SRC     =	main.c \
		wolf3d.c

OBJS    =       $(SRC:.c=.o)

CC	+=	-g

CFLAGS  +=      -I ./include/

IFLAGS  +=      -lmy -L ./lib/my/

LDLIBS	+=	-lmlx -lXext -lX11

NAME    =       wolf3d

.PHONY: all clean fclean re

all:            $(NAME)

$(NAME):        $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS) -lm $(IFLAGS)

clean:
	$(RM) $(OBJS)

fclean:         clean
	$(RM) $(NAME)

re:             fclean all
