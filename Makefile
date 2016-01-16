##
## Makefile for darnat_a in /home/darnat_a/rendu/PSU_2014_malloc
## 
## Made by Alexis Darnat
## Login   <darnat_a@epitech.net>
## 
## Started on  Tue Jan 27 16:05:13 2015 Alexis Darnat
## Last update Sat Mar 21 17:05:52 2015 
##

SRC		= $(filter-out %~, $(shell ls sources))

CFLAGS		= -W -Werror -Wall -Wextra -pedantic -I headers

OBJ		= $(addprefix objects/,$(SRC:.c=.o))

CC		= gcc

NAME		= gomoku

all		: $(NAME)

$(NAME)		: $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

objects/%.o: sources/%.c
		@mkdir -p objects
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all

.PHONY	: all clean fclean re

