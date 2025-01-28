# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 09:01:45 by fpedraza          #+#    #+#              #
#    Updated: 2025/01/28 23:11:48 by fpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# * Variables
SRCS_SERVER		=	server.c
SRCS_CLIENT		=	client.c
OBJS_DIR		=	obj
OBJS_SERVER 	=	$(addprefix $(OBJS_DIR)/, $(SRCS_SERVER:.c=.o))
OBJS_CLIENT 	=	$(addprefix $(OBJS_DIR)/, $(SRCS_CLIENT:.c=.o))
OBJS 			=	$(OBJS_SERVER) $(OBJS_CLIENT)
BIN_DIR			=	bin
BIN_SERVER		=	$(addprefix $(BIN_DIR)/, "server")
BIN_CLIENT		=	$(addprefix $(BIN_DIR)/, "client")
BINARIES		= 	$(BIN_SERVER) $(BIN_CLIENT)

CC 				=	cc
CC_FLAGS 		= 	-Wall -Werror -Wextra
RM_RF 			= 	rm -rf
NAME 			=	minitalk

# Libft
LIBFT_DIR		=	src/libft
LIBFT 			=	$(LIBFT_DIR)/libft.a

# Colors
GREEN			= \033[1;32m
CYAN			= \033[36m
WHITE			= \033[0m
PURPLE			= \033[1;35m

# Main rule
all: $(NAME)

$(NAME): $(LIBFT) MSG $(OBJS)
				@mkdir -p $(BIN_DIR)
				@echo "\nBuilding [$(GREEN)minitalk$(WHITE)]\n"
				@$(CC) $(CC_FLAGS) -o $(BIN_SERVER) $(OBJS_SERVER) $(LIBFT)
				@$(CC) $(CC_FLAGS) -o $(BIN_CLIENT) $(OBJS_CLIENT) $(LIBFT)
				@echo "Built -> [$(PURPLE)$(BIN_SERVER)$(WHITE)]"
				@echo "Built -> [$(PURPLE)$(BIN_SERVER)$(WHITE)]"
				@echo "\n... ✅ Everything compiled successfully ✅ ...\n"

MSG:
				@echo "\nCompiling [$(GREEN)$(NAME)$(WHITE)]"

# Build libft
$(LIBFT):
				@echo "\nCompiling [$(GREEN)libft$(WHITE)]"
				@$(MAKE) -C $(LIBFT_DIR) || exit 1

# [GENERIC] Compile all .c files into .o files
$(OBJS_DIR)/%.o: %.c
				@mkdir -p $(OBJS_DIR)
				@echo "Compiling object $< -> [$(CYAN)$@$(WHITE)]"
				@$(CC) $(CC_FLAGS) -c $< -o $@

#! Other Rules
libft_clean:
				@$(MAKE) -C $(LIBFT_DIR) fclean

clean:			libft_clean
				@$(RM_RF) $(OBJS_DIR)
				@echo " -> [$(GREEN)+$(WHITE)] [$(CYAN)Minitalk objects$(WHITE)] [$(GREEN)+$(WHITE)] cleaned successfully 🗑️"

fclean:			clean
				@$(RM_RF) $(BINARIES)
				@$(RM_RF) $(BIN_DIR)
				@echo " -> [$(GREEN)+$(WHITE)] [$(CYAN)Minitalk binaries$(WHITE)] [$(GREEN)+$(WHITE)] cleaned successfully 🗑️"

re:				fclean $(NAME)

# Compile libft rule
libft: $(LIBFT)

.PHONY:			all clean fclean re MSG
