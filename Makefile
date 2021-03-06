# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsunki <minsunki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 23:04:25 by minsunki          #+#    #+#              #
#    Updated: 2022/02/25 02:12:37 by minsunki         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCF		=	sources
SRCF_B		=	bonus
INCF		=	includes

FIL_M		=	hook \
				main \
				map_parse \
				map_validate \
				meta \
				mexit \
				mmlx \
				texture \
				render \
				player


FIL_B		=	patrol \

SRCS_M		=	$(addsuffix .c, $(addprefix $(SRCF)/, $(FIL_M)))
SRCS_B		=	$(addsuffix _bonus.c, $(addprefix $(SRCF_B)/, $(FIL_M) $(FIL_B)))

OBJS_M		=	$(SRCS_M:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

CC			=	gcc
CFLAGS		=	-O3 -Wall -Wextra -Werror
CFLAG_EXT	=	-Lmlx_linux -lmlx \
				-L/usr/lib -lXext -lX11 -lm -lz \
				-Llibft -lft 
RM			=	rm -f

%.o			:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJS_M)
			make all -C libft
			$(CC) $(OBJS_M) $(CFLAG) $(CFLAG_EXT) -o $(NAME)

bonus		:	$(OBJS_B)
			make all -C libft
			$(CC) $(OBJS_B) $(CFLAG) $(CFLAG_EXT) -o $(NAME)

clean		:
			$(RM) $(OBJS_M) $(OBJS_B)
			make clean -C libft

all			:	$(NAME)

fclean		:	clean
			$(RM) $(NAME)
			make fclean -C libft

re			:	fclean all


.PHONY		:	.c.o all clean fclean re bonus
