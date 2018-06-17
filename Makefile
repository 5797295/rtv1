# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 17:53:50 by jukim             #+#    #+#              #
#    Updated: 2018/06/15 15:17:09 by jukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = RTv1

SRC = main.c

OBJ = $(SRC:.c=.o)
MLX = -L $(MLXDIR) -g -fsanitize=address -lmlx -framework OpenGL -framework Appkit

SRCDIR = srcs
OBJDIR = objs
LIBDIR = lib/Libft
MLXDIR = lib/minilibx_macos

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
LIBS = $(LIBDIR)/libft.a $(MLX)
HEADER = -I includes -I $(LIBDIR)/ -I $(MLXDIR)

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re
.SUFFIXES: .c .o

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes -I $(MLXDIR) $< -o $@

$(NAME): $(OBJS)
	@make -C $(MLXDIR)
	@make -C $(LIBDIR)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "\033[0;31m\033[1m\(>ㅠ<)/"

clean:
	@/bin/rm -rf $(OBJDIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f $(LIBDIR)/libft.a

re: fclean all
