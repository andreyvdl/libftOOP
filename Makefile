# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:33:39 by adantas-          #+#    #+#              #
#    Updated: 2024/04/08 00:10:05 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FLAGS=-Wall -Wextra -Werror -std=c99
PART1=${wildcard code/part_1/*.c}
PART2=${wildcard code/part_2/*.c}
FOWARD_LIST=${wildcard code/foward_list/*.c}
EXTRAS=${wildcard code/extras/*.c}
SOURCES=${wildcard code/part_1/*.c code/part_2/*.c code/foward_list/*.c}
OBJECTS=${SOURCES:.c=.o}
HEADERS=${wildcard headers/*.h}

all: ${NAME}
.PHONY: all

${NAME}: ${HEADERS} ${OBJECTS}

clean:
.PHONY: clean

fclean: clean
.PHONY: fclean

re: fclean all
.PHONY: re
