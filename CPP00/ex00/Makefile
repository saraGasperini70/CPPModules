NAME = megaphone

SRC = megaphone.cpp\

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling...\n"
	@$(FLAGS) $(SRC) -o $(NAME)
	@echo "READY.\n"

clean:
	@rm -rf megaphone.o
	@echo "Object deleted\n"

fclean: clean
	@rm -rf megaphone.o $(NAME)
	@echo "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
