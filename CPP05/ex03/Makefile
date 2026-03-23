NAME = intern

SRCS = main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@echo "Compiling...\n"
	@$(FLAGS) $(SRCS) -o $(NAME)
	@echo "READY.\n"

clean:
	@rm -rf *.o
	@echo "Object deleted\n"

fclean: clean
	@rm -rf *.o $(NAME)
	@echo "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
