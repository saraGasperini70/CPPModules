NAME = serialize

SRCS = main.cpp \
		Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling $@..."
	@$(CXX) $(FLAGS) -o $@ $^
	@echo "Compilation done."

%.o: %.cpp
	@echo "Compiling $<..."
	@$(CXX) $(FLAGS) -c $< -o $@
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
	@echo "Recompiling..."
	@$(MAKE) all
	@echo "Recompiled."

.PHONY: all clean fclean re
