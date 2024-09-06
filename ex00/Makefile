NAME		=	btc
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17
_INCLUDE	=	include
INCLUDE		=	$(addprefix -I, $(_INCLUDE))

_HEADER		=	BitcoinExchange.hpp
HEADER		=	$(addprefix include/, $(_HEADER))
_SRC		=	main.cpp\
				BitcoinExchange.cpp
SRC			=	$(addprefix src/, $(_SRC))
OBJ			=	$(SRC:src/%.cpp=bin/%.o)

GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
CYAN		=	\033[0;36m
RESET		=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(YELLOW)%-80s$(RESET)\r" "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ $^
	@printf "$(GREEN)%-80s$(RESET)\n" "$(NAME) is ready!"

bin:
	@mkdir bin
	@echo "$(CYAN)Creating 'bin' directory$(RESET)"

bin/%.o: src/%.cpp $(HEADER) | bin
	@printf "$(YELLOW)%-80s$(RESET)\r" "Compiling $(notdir $@)..."
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@printf "$(RED)%-80s$(RESET)\r" "Removing object files..."
	@rm -rf bin/*
	@printf "$(GREEN)%-80s$(RESET)\n" "Object files removed!"

fclean: clean
	@printf "$(RED)%-80s$(RESET)\r" "Removing $(NAME)..."
	@rm -f $(NAME)
	@printf "$(GREEN)%-80s$(RESET)\n" "$(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re