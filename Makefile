##
## Makefile for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Aug 16 00:22:04 2013 Marin Alcaraz
## Last update Thu Nov 07 19:49:52 2013 Marin Alcaraz
##

NAME 	= 	chain_check

SRC 	= 	File_handler.cpp 		\
			Exception.cpp 			\
			main.cpp

OBJ 	= 	$(SRC:.cpp=.o)

CFLAGS 	= 	-Wall -Wextra

CC 		= 	g++

RM 		= 	rm -f
ECHO 	= 	echo

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -Wall -Werror -Wextra  $(CFLAGS) -o $(NAME)
		 	@$(ECHO) '> Compiled'

clean:
		$(RM) $(OBJ)
		@$(ECHO) '>Directory cleaned'

fclean: clean
		$(RM) $(NAME)
		@$(ECHO) '>Removed executable'

re: fclean all
