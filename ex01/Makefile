NAME = easyfind
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(SRC) -c <$ 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
