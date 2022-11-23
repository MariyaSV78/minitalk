# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 21:15:29 by msosnova          #+#    #+#              #
#    Updated: 2021/11/08 21:15:42 by msosnova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			MINITALK

SERVER =		server
CLIENT =		client

SERVER_BONUS = 	server_bonus
CLIENT_BONUS =	client_bonus

CFLAGS =		-Wall -Werror -Wextra
CC =			gcc


SOURCES =	srcs/ft_putchar.c\
			srcs/ft_putstr.c\
			srcs/ft_putnbr.c\
			srcs/ft_atoi.c\
			srcs/ft_send_signal.c
INCLUDE =	include/

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): 
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SOURCES) $(SERVER).c -o $(SERVER)
	
$(CLIENT): 
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SOURCES) $(CLIENT).c -o $(CLIENT)
	
$(SERVER_BONUS): 
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SOURCES) $(SERVER_BONUS).c -o $(SERVER_BONUS)
	
$(CLIENT_BONUS): 
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SOURCES) $(CLIENT_BONUS).c -o $(CLIENT_BONUS)
	
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
	
clean:
	rm -f $(SERVER) $(SERVER_BONUS) $(CLIENT) $(CLIENT_BONUS)

fclean: clean

re: fclean all

.PHONY: all bonus clean fclean re
