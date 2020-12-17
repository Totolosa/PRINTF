NAME		= libftprintf.a

SRCS		= 	ft_printf.c\
				reconize_table.c\
				print_other_than_arg.c\
				print_char.c\
				print_str.c\
				print_int.c\
				print_ptr.c\
				print_percent.c\
				check_width.c\
				check_precision.c\
				basic_fonctions.c\

OBJS		= $(SRCS:.c=.o)

CC          = gcc

CFLAGS      = -Wall -Werror -Wextra -I. -c

RM          = rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^

%.o:		%.c printf.h
			$(CC) $(CFLAGS) $<

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	clean fclean all re
