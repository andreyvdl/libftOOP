# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:33:39 by adantas-          #+#    #+#              #
#    Updated: 2024/05/04 11:34:41 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
FLAGS=-Wall -Wextra -Werror -std=c99
SOURCES=$(addprefix code/, \
	$(addprefix extras/, ft_islower.c ft_isspace.c ft_isupper.c) \
	$(addprefix part_1/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c)\
	$(addprefix part_2/, ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_striteri.c ft_strjoin.c \
		ft_strmapi.c ft_strtrim.c ft_substr.c)\
	$(addprefix foward_list/, ft_lst_add_back.c ft_lst_add_front.c \
		ft_lst_clear.c ft_lst_del_one.c ft_lst_iter.c ft_lst_last.c \
		ft_lst_map.c ft_lst_new.c ft_lst_size.c flist_object.c ft_lst_at.c \
		ft_lst_rev.c ft_lst_find.c ft_lst_merge.c)\
	$(addprefix gnl/, ft_gnl_clear.c ft_gnl_read.c ft_gnl_set_fd.c \
		gnl_object.c)\
)
OBJECTS=$(addprefix objects/, $(notdir $(SOURCES:.c=.o)))
HEADERS=headers/libft.h headers/foward_list.h headers/gnl.h
VPATH=code/extras:code/part_1:code/part_2:code/foward_list:code/gnl

all: $(NAME)
.PHONY: all

$(NAME): dir $(HEADERS) $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

objects/%.o: %.c $(HEADERS)
	cc $(FLAGS) -c $< -o $@

dir:
	@mkdir -p objects
.PHONY: dir

clean:
	@rm -fr objects
.PHONY: clean

fclean: clean
	@rm -fr ${NAME}
.PHONY: fclean

re: fclean all
.PHONY: re
