# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jsiegers <jsiegers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: Invalid date        by jsiegers      #+#    #+#                  #
#    Updated: 2022/12/17 19:45:06 by jsiegers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS	= main.cpp PhoneBook.cpp Contact.cpp
OBJS	= ${SRCS:.cpp=.o}
NAME	= phonebook 
CFLAGS	= -Wall -Wextra -Werror

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
