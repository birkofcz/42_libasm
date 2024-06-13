# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 17:26:19 by sbenes            #+#    #+#              #
#    Updated: 2023/08/06 17:28:59 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the source file without the extension
TARGET = hello_world

# Assembler, Linker, and flags
AS = nasm
ASFLAGS = -f elf64
LD = ld
LDFLAGS =

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(LD) $(LDFLAGS) -o $@ $<

$(TARGET).o: $(TARGET).asm
	$(AS) $(ASFLAGS) $<

clean:
	rm -f $(TARGET).o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
