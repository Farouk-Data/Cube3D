# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 16:04:53 by ababouel          #+#    #+#              #
#    Updated: 2022/09/27 00:23:56 by fech-cha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g 
BDIR = build
FILES = main draw/drawline \
	parsing/parsing_tools \
	events/events parsing/parsing \
	parsing/get_next_line \
	parsing/get_next_line_utils \
	parsing/split \
	parsing/ft_atoi
NAME = cub3d
HEADERS = inc/data.h inc/parsing.h inc/draw.h  inc/raycast.h inc/events.h
INC = -I ./inc
OBJ = $(addprefix $(BDIR)/, $(FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^  ./lib/libmlx.a -framework OpenGL -framework AppKit -o $@ 
	@printf "$(GREEN)Done !"

$(BDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $<   -o $@ -I ./inc
	 
clean:
	rm -rf $(BDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re all clean fclean