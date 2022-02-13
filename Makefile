# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:16:14 by wyu               #+#    #+#              #
#    Updated: 2022/02/13 08:58:00 by wyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar rcs
RM 		= rm -f

INFO_DIR 	= info/
PRINT_DIR 	= print/
SET_DIR 	= set/
UTILL_DIR 	= utill/

INFO 		= filter_info init_info
PRINT 		= print_address print_char print_hex print_info\
				print_int print_notation print_precision print_sign print_space_prefix\
				print_space_postfix print_string print_unsigned print_zero
SET 		= precision_redefine set_flag set_info set_precision set_specifier set_width\
				width_redefine
UTILL 		= ft_putchar ft_putstr

NAME 		= libftprintf.a
LIBFT 		= libft
LIBFT_NAME 	= libft.a

INFO_SRCS 	= $(addprefix $(INFO_DIR), $(addsuffix .c, $(INFO)))
PRINT_SRCS 	= $(addprefix $(PRINT_DIR), $(addsuffix .c, $(PRINT)))
SET_SRCS 	= $(addprefix $(SET_DIR), $(addsuffix .c, $(SET)))
UTILL_SRCS 	= $(addprefix $(UTILL_DIR), $(addsuffix .c, $(UTILL)))
SRCS 		= $(INFO_SRCS) $(PRINT_SRCS) $(SET_SRCS) $(UTILL_SRCS) ft_printf.c

INFO_OBJS 	= $(addsuffix .o, $(INFO))
PRINT_OBJS 	= $(addsuffix .o, $(PRINT))
SET_OBJS 	= $(addsuffix .o, $(SET))
UTILL_OBJS 	= $(addsuffix .o, $(UTILL))
OBJS 		= $(INFO_OBJS) $(PRINT_OBJS) $(SET_OBJS) $(UTILL_OBJS) ft_printf.o

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)/$(LIBFT_NAME)
		$(AR) $@ $(OBJS)

$(LIBFT)/$(LIBFT_NAME) : 
		make all -C $(LIBFT)
		cp $(LIBFT)/$(LIBFT_NAME) $(NAME)

$(OBJS) : $(SRCS)
		$(CC) $(CFLAGS) -c $^

clean : 
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean : clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re : clean all