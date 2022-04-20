NAME 		= push_swap

CC 			= gcc
FLAGS 		= -Wall -Wextra -Werror -g
RM			= rm -rf

SRC_F 		= main.c
SRC			= $(addprefix ./src/, $(SRC_F))
OBJ			= $(addprefix ./obj/, $(OBJ_F))
OBJ_F		= $(SRC_F:.c=.o)

HEADER_F 	= push_swap.h
HEADER		= $(addprefix ./head/, $(HEADER_F))

#COMMANDS

all: $(NAME)

$(OBJ): $(SRC) $(HEADER) Makefile
	@ echo $(CURSIVE) $(YELLOW) " - Making Objects $<..." $(NONE)
	@ $(CC) -c $< -o $@
	@ echo $(GREEN) " - Objects Created !" $(NONE)

$(NAME): $(OBJ)
	@ echo $(CURSIVE) $(YELLOW) " - Compiling Objects $@..." $(NONE)
	@ $(CC) $< -o $@
	@ echo $(GREEN) " - Compiled !" $(NONE)


clean:
	@ echo $(RED) " - Deleting Objects: $(OBJ)" $(NONE)
	@ $(RM) $(OBJ)
	@ echo $(GREEN) " - Objects deleted !" $(NONE)

fclean: clean
	@ echo $(RED) " - Deleting $(NAME)..." $(NONE)
	@ $(RM) $(NAME)
	@ echo $(RED) " - $(NAME) Deleted !" $(NONE)

re: fclean all
	
#COLORS

NONE='\033[0m'
RED ='\033[1;31m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'