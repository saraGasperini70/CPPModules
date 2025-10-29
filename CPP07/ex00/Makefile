NAME = templates

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@echo "Compiling $@..."
	@$(FLAGS) $(SRCS) -o $@ $^
	@echo "Compilation done."

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJS)
	@echo "Cleaned up."

fclean: clean
	@echo "Cleaning up..."
	@rm -f $(NAME)
	@echo "Cleaned up."

re: fclean all

.PHONY: all clean fclean re
