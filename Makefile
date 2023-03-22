# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joestrad <joestrad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 14:42:14 by joestrad          #+#    #+#              #
#    Updated: 2022/12/27 13:28:53 by joestrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

NAMES = server

NAMEB = client_bonus

NAMESB = server_bonus

INC_LFT = -Ilibft

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = client.c

SRCS = server.c

SRCB = client_bonus.c

SRCSB = server_bonus.c

OBJ = $(SRC:.c=.o)

OBJS = $(SRCS:.c=.o)

OBJB = $(SRCB:.c=.o)

OBJSB = $(SRCSB:.c=.o)

GREEN = "\033[32m"
RED = "\033[31m"
NOCOLOR = "\033[0m"

%.o: %.c
	@$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ) minitalk.h 
	@$(CC) $(FLAGS) $(INC_LFT) $(LIBFT) $(SRC) -o $(NAME)
	@echo $(GREEN)Client ready$(NOCOLOR)

$(NAMES): $(LIBFT) $(OBJS) minitalk.h
	@$(CC) $(FLAGS) $(INC_LFT) $(LIBFT) $(SRCS) -o $(NAMES)
	@echo $(GREEN)Server ready$(NOCOLOR)

$(LIBFT):
	@make -C libft --silent
	@make bonus -C libft --silent
	@echo $(GREEN)Libft ready$(NOCOLOR)

all: $(NAME) $(NAMES)
	@echo $(GREEN)Project minitalk built$(NOCOLOR)

$(NAMEB): $(LIBFT) $(OBJB) minitalk_bonus.h 
	@$(CC) $(FLAGS) $(INC_LFT) $(LIBFT) $(SRCB) -o $(NAMEB)
	@echo $(GREEN)Client with bonus ready$(NOCOLOR)

$(NAMESB): $(LIBFT) $(OBJSB) minitalk_bonus.h
	@$(CC) $(FLAGS) $(INC_LFT) $(LIBFT) $(SRCSB) -o $(NAMESB)
	@echo $(GREEN)Server with bonus ready$(NOCOLOR)

bonus:
	@make allbonus
	@echo $(GREEN)Project minitalk with bonus built$(NOCOLOR)

allbonus:	$(NAMEB) $(NAMESB)

clean:
	@$(RM) $(OBJ) $(OBJS) $(OBJB) $(OBJSB)
	@$(RM) libft/*.o
	@echo $(RED)Objects files cleaned$(NOCOLOR)

fclean: clean
	@$(RM) $(NAME) $(NAMES) $(NAMEB) $(NAMESB)
	@$(RM) $(LIBFT)
	@echo $(RED)Executables files cleaned$(NOCOLOR)

re: fclean all
	@echo $(RED)Cleaned$(NOCOLOR) and $(GREEN)rebuilt$(NOCOLOR) minitalk project

.PHONY: all clean fclean re bonus allbonus
