NAME 		= push_swap

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g
RM			= rm -rf

LIBFT		= ./libft/libft.a

SRC_DIR		= ./src/
SRC			= $(addprefix ./src/, $(SRC_F))
SRC_F 		= main.c list_ft.c swap.c push.c rotate.c reverse_rotate.c sort_algorithm.c

OBJ_DIR		= ./obj/
OBJ			= $(addprefix ./obj/, $(OBJ_F))
OBJ_F		= $(SRC_F:.c=.o)

HEADER_F 	= push_swap.h
HEADER		= $(addprefix ./head/, $(HEADER_F))

#COMMANDS

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ echo $(CURSIVE) $(YELLOW) " - Making Objects $<..." $(NONE)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ echo $(GREEN) " - Objects Created !" $(NONE)

$(NAME): $(OBJ) $(LIBFT)
	@ echo $(CURSIVE) $(YELLOW) " - Compiling Objects $<..." $(NONE)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@ echo $(GREEN) " - Compiled !" $(NONE)

$(LIBFT):
	@ echo $(CURSIVE) $(YELLOW) " - Making $(LIBFT)..." $(NONE)
	@ make all -C ./libft

clean:
	@ echo $(RED) " - Deleting Objects: $(OBJ)" $(NONE)
	@ $(RM) $(OBJ)
	@ make clean -C ./libft
	@ echo $(GREEN) " - Objects deleted !" $(NONE)

fclean: clean
	@ echo $(RED) " - Deleting $(NAME)..." $(NONE)
	@ $(RM) $(NAME)
	@ make fclean -C ./libft
	@ echo $(RED) " - $(NAME) Deleted !" $(NONE)

re: fclean all
	
#COLORS

NONE='\033[0m'
RED ='\033[1;31m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'