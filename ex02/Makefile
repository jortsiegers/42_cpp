# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsiegers <jsiegers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/25 00:22:23 by jsiegers      #+#    #+#                  #
#    Updated: 2023/05/26 15:17:24 by jsiegers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

MAIN    = main.cpp
SRCS	= ${MAIN}
OBJS	= ${SRCS:.cpp=.o}
NAME	= ./a.out 
CFLAGS	= -Wall -Wextra -Werror -g -std=c++98

.cpp.o:
	c++ ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}: ${OBJS}
	c++ ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o test
