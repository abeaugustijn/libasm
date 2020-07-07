# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:    :+:             #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/20 20:26:10 by aaugusti          #+#    #+#              #
#    Updated: 2020/07/07 21:07:14 by aaugusti      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

ASM			=	nasm -g
CC			=	gcc
LD			=	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2

SRCS		=	read\
				strcmp\
				strcpy\
				strdup\
				strlen\
				write\

OFILES		=	$(SRCS:%=ft_%.o)
TEST_OFILES	=	$(SRCS:%=test/ft_%.o)

FLAGS		=	-Wall -Werror -Wextra -O0 -g

all: $(NAME)

$(NAME): $(OFILES)
	ld $(INCLUDES) -o $(NAME) $(OFILES)

test: $(OFILES) $(TEST_OFILES) test/main.o
	$(LD) test/main.o -lc $(INCLUDES) $(OFILES) $(TEST_OFILES) -e "main"

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

%.o: %.asm
	$(ASM) -f elf64 $< -o $@

clean:
	rm -rf $(OFILES) $(TEST_OFILES) test/main.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

testre: fclean test
