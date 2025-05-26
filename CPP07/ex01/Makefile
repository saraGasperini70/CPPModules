NAME = iter

SRCS = main.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling..."
	@$(CXX) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "Done!"

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(FLAGS) -c $< -o $@
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
