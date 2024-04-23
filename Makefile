# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:33:39 by adantas-          #+#    #+#              #
#    Updated: 2024/04/22 23:29:34 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FLAGS=-Wall -Wextra -Werror -std=c99
SOURCES=${addprefix code/, \
	${addprefix extras/, ft_islower.c ft_isspace.c ft_isupper.c} \
	${addprefix part_1/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlen.c}\
}
OBJECTS=${addprefix objects/, ${notdir ${SOURCES:.c=.o}}}
HEADERS=headers/libft.h
VPATH=code/extras:code/part_1

all: ${NAME}
.PHONY: all

${NAME}: dir ${HEADERS} ${OBJECTS}
	@ar rcs ${NAME} ${OBJECTS}

objects/%.o: %.c ${HEADERS}
	cc ${FLAGS} -c $< -o $@

dir:
	@mkdir -p objects
.PHONY: dir

clean:
	rm -fr objects
.PHONY: clean

fclean: clean
	@rm -fr ${NAME}
.PHONY: fclean

re: fclean all
.PHONY: re

libcassert.a:
	make -C libCAssert
	cp libCAssert/libcassert.a ./libft.a

test: libcassert.a all
	cc $(FLAGS) tester.c -L. -lft -o test.elf
.PHONY: test
