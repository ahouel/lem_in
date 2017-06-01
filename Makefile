# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahouel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 08:37:55 by ahouel            #+#    #+#              #
#    Updated: 2017/05/31 16:26:39 by ahouel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = ./lem_in
VPATH = ./srcs/
HDIR = ./includes
LDIR = ./libft
FCTS = main \
	   lem_in_init \
	   parser \
	   cells_parser \
	   links_parser
SRCS = $(addsuffix .c, $(FCTS))
SRC = $(addprefix $(VPATH), $(SRCS))
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[34m\033[1mCompilation de la lib...\033[0m"
	@make -C $(LDIR)
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mCompilation de lem_in...\033[0m"
	@$(CC) $(CFLAGS) -L$(LDIR) -lft $(OBJ) -o $(NAME)
	@printf "\033[A\033[K"
	@echo "\033[34m\033[1mLem_in done !\033[0m"

%.o : $(VPATH)%.c
	@echo "\033[34m\033[1mCompilation de $(notdir $<)...\033[0m\r"
	@$(CC) -c $(CFLAGS) -I $(HDIR) -I $(LDIR)/includes $<
	@printf "\033[A\033[K"

clean :
	@rm -f $(OBJ)
	@make -C $(LDIR) clean

fclean : clean
	@rm -f $(NAME)
	@make -C $(LDIR) fclean

re : fclean all

.PHONY : all clean fclean re
