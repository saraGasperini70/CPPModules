NAME = intern

SRCS = main.cpp Bureaucrat.cpp AForm.cpp Intern.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@printf "Compiling...\n"
	@$(FLAGS) $(OBJS) -o $(NAME)
	@printf "READY.\n"

clean:
	@rm -rf *.o
	@printf "Object deleted\n"

fclean: clean
	@rm -rf *.o $(NAME)
	@printf "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
