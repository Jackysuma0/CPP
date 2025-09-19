NAME = easyfind

CC = c++ -Wall -Wextra -Werror -std=c++98 -g3

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@echo " \033[0;32mObject files cleaned!\033[0m"

fclean: clean
	$(RM) $(NAME) 
	@echo " \033[0;32mExecutables cleaned!\033[0m"

re: fclean all

PHONY: all clean fclean re