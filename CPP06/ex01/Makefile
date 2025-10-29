NAME = serialize

SRCS = main.cpp \
		Serializer.cpp

OBJS = $(SRCS:.cpp=.o)

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	@echo "Compiling ...\n"
	@$(FLAGS) $(SRCS) -o$(NAME)
	@echo "Compilation done."

clean:
	@rm -f *.o
	@echo "Cleaned up."

fclean: clean
	@rm -f *.o $(NAME)
	@echo "Cleaned up."

re: fclean all

.PHONY: all clean fclean re
