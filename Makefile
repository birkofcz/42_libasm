#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 12:26:28 by sbenes            #+#    #+#              #
#    Updated: 2024/06/17 17:00:36 by sbenes           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME        = libasm.a
SRC_DIR     = src
SRC_FILES   = ft_strlen.s ft_strcpy.s
OBJ_FILES   = $(SRC_FILES:%.s=$(SRC_DIR)/%.o)
INCLUDE_DIR = include

all: $(NAME)

$(NAME): $(OBJ_FILES)
		@echo "Creating library..."
		@ar rc $(NAME) $(OBJ_FILES)
		@ranlib $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.s
		@echo "Compiling $<..."
		@nasm -f elf64 -o $@ $<

clean:
		@echo "Cleaning all .o files"
		@rm -f $(OBJ_FILES)

fclean: clean
		@echo "Deleting library..."
		@rm -f $(NAME)
		@if [ -f test ]; then \
			echo "Deleting test executable..."; \
			rm -f test; \
		fi

re: fclean all

test: $(NAME)
		@echo "Compiling test program..."
		@cc -o test main.c $(NAME) -I$(INCLUDE_DIR)

.PHONY: all clean fclean re test

