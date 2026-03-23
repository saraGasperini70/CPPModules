NAME = animal_virtual

SRC = main.cpp\
	Animal.cpp\
	Cat.cpp\
	Dog.cpp\
	WrongAnimal.cpp\
	WrongCat.cpp\

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

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
