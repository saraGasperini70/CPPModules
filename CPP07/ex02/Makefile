NAME = array

SRCS = main.cpp \

INCS = Array.hpp \
		Array.tpp \


OBJS = $(SRCS:.cpp=.o)

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

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
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
