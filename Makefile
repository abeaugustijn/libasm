# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/20 20:26:10 by aaugusti          #+#    #+#              #
#    Updated: 2020/03/21 18:53:07 by aaugusti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libasm.a
ASM					=	nasm

SRCS				=	strlen\
						strcmp\
						strcpy\
						write\

AMS_FILES			=	$(SRCS:%=ft_%.asm)
OFILES				=	$(SRCS:%=ft_%.o)

TEST_CFILES			=	$(SRCS:%=test/ft_%.c)
TEST_OFILES			=	$(SRCS:%=test/ft_%.o)

FLAGS				=	-Wall -Werror -Wextra -O0 -g

all: $(NAME)

$(NAME): $(OFILES)
	ar rs $(NAME) $(OFILES)


test: $(OFILES) $(TEST_OFILES) test/main.o
	$(CC) $(FLAGS) $(OFILES) $(TEST_OFILES) test/main.o

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

%.o: %.asm
	$(ASM) -f elf64 $< -o $@

clean:
	rm -rf $(OFILES) $(TEST_OFILES)

fclean: clean
	rm -rf $(NAME)
