# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aaugusti <aaugusti@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/03/20 20:26:10 by aaugusti      #+#    #+#                  #
#    Updated: 2020/07/28 15:27:07 by aaugusti      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

AR			=	ar rs
ASM			=	nasm
CC			=	gcc
LD			=	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 --pic-executable

SRCS		=	\
				read\
				strcmp\
				strcpy\
				strdup\
				strlen\
				write\

OFILES		=	$(SRCS:%=ft_%.o)
TEST_OFILES	=	$(SRCS:%=test/ft_%.o)

CCFLAGS		=	-Wall -Werror -Wextra -O0 -g
ASMFLAGS	=	-g -f macho64

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)

test: $(NAME) $(TEST_OFILES) test/main.o
	$(CC) $(CCFLAGS) -L. -lasm test/main.o $(TEST_OFILES) -o test.out

%.o: %.c
	$(CC) -o $@ -c $< $(CCFLAGS)

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf $(OFILES) $(TEST_OFILES) test/main.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

testre: fclean test
