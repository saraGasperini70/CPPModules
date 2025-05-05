NAME = shrubbery

SRC = main.cpp\
	ShrubberyCreationForm.cpp\
	Bureaucrat.cpp\
	AForm.cpp\

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

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
