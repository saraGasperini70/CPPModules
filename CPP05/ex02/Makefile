NAME = forms

SRC = main.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp\
	Bureaucrat.cpp\
	AForm.cpp\

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

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
	@rm -rf default_shrubbery
	@echo "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
