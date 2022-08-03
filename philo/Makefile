# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 16:33:50 by mkim3             #+#    #+#              #
#    Updated: 2022/08/03 17:10:08 by mkim3            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC=gcc
FLAGS=-Werror -Wall -Wextra
SRCS=./exception.c ./linked_list_init.c ./main.c \
./parsing_input.c ./ft_create_philosopher.c ./philosopher.c \
./ft_time_util.c ./ft_state.c
OBJS=$(SRCS:.c=.o)
INCLUDES=./philosophers.c
NAME=philo
all : $(NAME)

.c.o:
	$(GCC)  -I $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(GCC)  -I $(INCLUDES) $^ -o $@
clean :  
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY = all clean fclean re