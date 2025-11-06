NAME = iter

SRCS = main.cpp

FLAGS = -c++ -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(FLAGS) $(SRCS) -o $@ $^
	@echo "Done!"

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJS)
	@echo "Done!"

fclean: clean
	@echo "Cleaning up..."
	@rm -f $(NAME)
	@echo "Done!"

re: fclean all

.PHONY: all clean fclean re
