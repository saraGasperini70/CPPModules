NAME = btc

SRCS = BitcoinExchange.cpp \
	main.cpp \
	utils.cpp \

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
	@echo "Compiling...\n"
	@$(FLAGS) $(SRCS) -o $(NAME)
	@echo "READY.\n"

clean:
	@rm -rf *.o
	@echo "Object deleted\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
