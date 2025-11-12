NAME = btc

SRCS = BitcoinExchange.cpp \
	main.cpp \

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME):
	@printf "Compiling...\n"
	@$(FLAGS) $(SRCS) -o $(NAME)
	@printf "READY.\n"

clean:
	@rm -rf *.o
	@printf "Object deleted\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "All cleared\n"

re: fclean all

.PHONY: all clean fclean re
