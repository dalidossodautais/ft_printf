# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddosso-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/14 00:26:06 by ddosso-d          #+#    #+#              #
#    Updated: 2017/02/14 00:26:09 by ddosso-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-Wall -Wextra -Werror
FILES	=	printf analyze informations put putcase init len \
			non_printable case_c case_s case_d case_o \
			case_p case_u case_x case_k case_e case_f case_m \
			to too tooo normal \
			sprintf snprintf fprintf vprintf vsprintf vsnprintf \
			vfprintf sanalyze sput
SRCS	=	$(addsuffix .c, $(FILES))
OBJS	=	$(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $@ $^
	@ranlib $@

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
