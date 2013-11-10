##
## Makefile for chaincheck in /Users/Marin/Dropbox/Code/chaincheck
##
## Made by Marin Alcaraz
## Login   <alcara_m@epitech.net>
##
## Started on  Fri Aug 16 00:22:04 2013 Marin Alcaraz
## Last update Sat Nov 09 22:59:09 2013 Marin Alcaraz
##

NAME 	= 	chain_check

SRC 	= 	File_handler.cpp 		\
			Exception.cpp 			\
			Grammar.cpp 			\
			Parser.cpp 				\
			main.cpp

OBJ 	= 	$(SRC:.cpp=.o)

CFLAGS 	= 	-Wall -Wextra -g3

CC 		= 	g++

RM 		= 	rm -f
ECHO 	= 	echo

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(OBJ) -Wall -Wextra $(CFLAGS) -o $(NAME)
		 	@$(ECHO) '> Compiled'

clean:
		$(RM) $(OBJ)
		@$(ECHO) '>Directory cleaned'

fclean: clean
		$(RM) $(NAME)
		@$(ECHO) '>Removed executable'

re: fclean all
