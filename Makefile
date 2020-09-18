# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 10:59:50 by fulldemo          #+#    #+#              #
#    Updated: 2020/02/02 11:51:53 by fulldemo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
EXEC		= test

DIR_HEADERS	= ./includes/
DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/

SRC			= 	ft_strlen.s \
				ft_strcpy.s \
				ft_strcmp.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s \

MAIN_SRC	= main.c

SRCS		= $(SRC)
OBJS		= $(SRCS:%.s=$(DIR_OBJS)%.o)
MAIN_OBJ	= $(MAIN_SRC:%.c=$(DIR_OBJS)%.o)

CC			= gcc
CC_FLAGS	= -Wall -Wextra -Werror
NASM		= nasm
NASM_FLAG	= -f macho64
AR			= ar -rc
RANLIB		= ranlib

#		TEST		#
$(NAME):	$(OBJS)
					$(AR) $(NAME) $(OBJS)
					ranlib $(NAME)
		
$(EXEC):	$(NAME) $(MAIN_OBJ)
					$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(NAME) $(MAIN_OBJ) -o $(EXEC)

$(OBJS):	| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.s
					$(NASM) $(NASM_FLAG) -I $(DIR_HEADERS) -s $< -o $@

$(DIR_OBJS)%.o: %.c
					$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@
$(DIR_OBJS):
					mkdir $(DIR_OBJS)

#		OBLIGATORY	#
all:				$(NAME)

clean:
						rm -rf $(DIR_OBJS)
						rm -rf $(EXEC)
			
fclean:				clean
						rm -rf $(NAME)

re:						fclean all

.PHONY:				all, clean, fclean, re