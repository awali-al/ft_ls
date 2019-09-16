# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 14:26:42 by aminewalial       #+#    #+#              #
#    Updated: 2019/09/15 15:56:36 by awali-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRC_FILES =  ft_ls.c options.c

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ_DIR = .obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIB = libft/libft.a

HEADER = includes/ft_ls.h

all : $(NAME)

$(NAME) : $(OBJ)
	echo $(OBJ)
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) $(OBJ) $(LIB) -o $(NAME)

$(OBJ) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	gcc $(FLAGS) -c $< -I $(HEADER) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean :
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re : fclean all
