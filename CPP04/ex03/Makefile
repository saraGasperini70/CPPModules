NAME = interface_recap

SRC = $(wildcard *.cpp)

FLAGS = c++ -Wall -Wextra -Werror -std=c++98 -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling...\n"
	@$(FLAGS) $(SRC) -o $(NAME)
	@echo "READY.\n"

clean:
	@rm -rf *.o
	@echo "Object deleted\n"

fclean: clean
	@rm -rf *.o $(NAME)
	@echo "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
