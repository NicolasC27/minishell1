##
## Makefile for Makefile in /home/cheval_8/rendu/PSU_2015_minishell1
## 
## Made by Nicolas Chevalier
## Login   <cheval_8@epitech.net>
## 
## Started on  Tue Jan  5 16:23:58 2016 Nicolas Chevalier
## Last update Sat Mar 26 16:16:16 2016 Chevalier Nicolas
##

CC	= 	gcc

RM	= 	rm -f

CFLAGS	=  	-Wall -Iinclude/

NAME	= 	mysh

SRCS	= 	main.c \
		utils.c \
		init_listenv.c \
		my_str_to_wordtab.c \
		check_command.c \
		utils_env.c \
		my_exec.c \
		my_str.c \
		my_builtin.c \
		my_builtin_cd.c \
		my_getnbr.c \
		my_free.c \
		my_puterror.c

OBJS	= 	$(addprefix src/, $(SRCS:.c=.o))

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

# -W -Wall -Werror -Wextra -pedantic 
