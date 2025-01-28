# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedraza <fpedraza@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 10:02:45 by fpedraza          #+#    #+#              #
#    Updated: 2025/01/28 22:26:44 by fpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_strtrim.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_striteri.c
OBJS 			=	$(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		=	$(BONUS:.c=.o)
CC 				=	gcc
CC_FLAGS 		= 	-Wall -Werror -Wextra
RM_RF 			= 	rm -rf
NAME 			= 	libft.a

# Colors
GREEN			= \033[32m
CYAN			= \033[36m
WHITE			= \033[0m

# Main target
all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "\nCreating library $(CYAN)$(NAME)$(WHITE)...\n"
				@ar crs $(NAME) $(OBJS)

# Compile .c files to .o files
%.o: %.c
				@echo "Compiling: $(CYAN)$<$(WHITE) -> $(CYAN)$@$(WHITE)"
				@$(CC) $(CC_FLAGS) -c $< -o $@

bonus:			$(OBJS) $(BONUS_OBJS)
				@echo "Creating bonus objects..."
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
				@$(RM_RF) $(OBJS) $(BONUS_OBJS)
				@echo " -> [$(GREEN)+$(WHITE)] [$(CYAN)Libft objects$(WHITE)] cleaned successfully 🗑️"

fclean:			clean
				@$(RM_RF) $(NAME)
				@echo " -> [$(GREEN)+$(WHITE)] [$(CYAN)Libft binaries$(WHITE)] [$(GREEN)+$(WHITE)] cleaned successfully 🗑️"

re:				fclean all

so:
				@echo "Building shared library libft.so..."
				@$(CC) -nostartfiles -fPIC $(CC_FLAGS) -c $(SRCS)
				@$(CC) -nostartfiles -shared -o libft.so $(OBJS)
				@echo " -> [$(GREEN)+$(WHITE)] [$(CYAN)libft.so$(WHITE)] created successfully ✅"

.PHONY:			all clean fclean re bonus
