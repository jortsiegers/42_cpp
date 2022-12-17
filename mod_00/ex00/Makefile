# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsiegers <jsiegers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/25 00:22:23 by jsiegers      #+#    #+#                  #
#    Updated: 2022/12/02 10:33:09 by jsiegers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS	= megaphone.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= megaphone 
CFLAGS  = -Wall -Wextra -Werror

.c.o:
	c++ ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	c++ ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o
