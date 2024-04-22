NAME = megaphone

SRC = megaphone.cpp\

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@printf "Compiling...\n"
	@$(FLAGS) $(SRC) -o $(NAME)
	@printf "READY.\n"

clean:
	@rm -rf megaphone.o
	@printf "Object deleted\n"

fclean: clean
	@rm -rf megaphone.o $(NAME)
	@printf "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
