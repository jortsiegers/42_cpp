# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsiegers <jsiegers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/25 00:22:23 by jsiegers      #+#    #+#                  #
#    Updated: 2022/12/17 19:39:44 by jsiegers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS	= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= a.out 
CFLAGS	= -Wall -Wextra -Werror -std=c++98

.c.o:
	c++ ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
	c++ ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o
