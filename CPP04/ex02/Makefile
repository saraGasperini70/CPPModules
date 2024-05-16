NAME = animal_abstract

SRC = main.cpp\
	AAnimal.cpp\
	ADog.cpp\
	Animal.cpp\
	Brain.cpp\
	Cat.cpp\
	Dog.cpp\

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@printf "Compiling...\n"
	@$(FLAGS) $(SRC) -o $(NAME)
	@printf "READY.\n"

clean:
	@rm -rf *.o
	@printf "Object deleted\n"

fclean: clean
	@rm -rf *.o $(NAME)
	@printf "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
