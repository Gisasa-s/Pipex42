# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 17:14:04 by ahernand          #+#    #+#              #
#    Updated: 2021/09/29 14:10:46 by ahernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

all: $(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/pipex.c										\
	   srcs/ft_path.c									\
	   srcs/ft_error.c									\
	   srcs/fts/ft_strjoin.c							\
	   srcs/fts/ft_strdup.c								\
	   srcs/fts/ft_strlen.c								\
	   srcs/fts/ft_split.c							

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# - - C L E A N I N G - - - - - - - - - - - - - - -  #

clean:
	rm -f $(OBJS)
	rm -f pipex

fclean:
	make clean
	rm -f outfile

test:
	@make fclean
	@make
	@cd ../pipex-tester && sh run.sh
	@make clean

re:	fclean all
