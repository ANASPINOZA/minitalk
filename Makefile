# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 14:13:58 by aadnane           #+#    #+#              #
#    Updated: 2022/05/14 14:15:24 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_S = server.c utils.c utils_bin_handle.c
SRCS_C = client.c utils.c utils_bin_handle.c
OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
SERVER = server
CLIENT = client

SRCS_BS = server_bonus.c utils.c
SRCS_BC = client_bonus.c utils.c
OBJS_BS = $(SRCS_BS:.c=.o)
OBJS_BC = $(SRCS_BC:.c=.o)
SERVER_B = server_bonus
CLIENT_B = client_bonus

NAME = minitalk
BONUS = minitalk_bonus
HEADER = minitalk.h

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S)
	$(CC) $(FLAGS) $(OBJS_S) -o $(SERVER)

$(CLIENT): $(OBJS_C)
	$(CC) $(FLAGS) $(OBJS_C) -o $(CLIENT)
 
bonus: $(BONUS)

$(BONUS): $(SERVER_B) $(CLIENT_B)
 
$(SERVER_B): $(OBJS_BS)
	$(CC) $(FLAGS) $(OBJS_BS) -o $(SERVER_B)

$(CLIENT_B): $(OBJS_BC)
	$(CC) $(FLAGS) $(OBJS_BC) -o $(CLIENT_B)

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS_C) $(OBJS_S) $(OBJS_BC) $(OBJS_BS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re: fclean all