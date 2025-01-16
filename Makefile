NAME = so_long
SRC = main.c
OBJ := $(SRC:%.c=%.o)
ARCHIVES = libmlx.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "\n→ $(NAME) compiled successfully \n"

%.o: %.c
	@echo "\n... $< ... ✅"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(ARCHIVES)


fclean: clean
	@rm -rf $(NAME)
	@echo "\n→ Make successfully cleaned files 🗑️"

re: fclean all

.PHONY: all clean fclean re
