# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 14:31:58 by lomont            #+#    #+#              #
#    Updated: 2025/12/08 01:49:33 by lomont           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = internSHIP

C++ = g++-15
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RM = rm -f

SRC = ./main.cpp \
		./Bureaucrat.cpp \
		./AForm.cpp \
		./ShrubberyCreationForm.cpp \
		./RobotomyRequestForm.cpp \
		./PresidentialPardonForm.cpp \
		./Intern.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(C++) $(CFLAGS) -c $< -o $@

make: make all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) *_shrubbery

re: fclean all

.PHONY : all clean fclean re
