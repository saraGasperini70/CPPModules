NAME = converter

SRCS = main.cpp \
		ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@printf "Compiling...\n"
	@$(FLAGS) $(SRCS) -o $(NAME)
	@printf "READY.\n"

clean:
	@rm -rf *.o
	@printf "Object deleted\n"

fclean: clean
	@rm -rf *.o $(NAME)
	@printf "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
