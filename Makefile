# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 19:33:39 by adantas-          #+#    #+#              #
#    Updated: 2024/04/07 19:38:32 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: ${NAME}
.PHONY: all

${NAME}: ${HEADER} ${OBJECTS}

clean:
.PHONY: clean

fclean: clean
.PHONY: fclean

re: fclean all
.PHONY: re

bonus: ${NAME_BONUS}
.PHONY: bonus

${NAME_BONUS}: ${HEADER_BONUS} ${OBJECTS_BONUS}

re_bonus: fclean bonus
.PHONY: re_bonus
