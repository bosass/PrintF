NAME = libftprintf.a

SRCS =	ft_printf.c \
		writetext.c \
		writehex.c \

		
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o:
	$(CC) $(FLAGS) -c $< -o $@ -I$(INCS)

$(NAME): $(OBJS)
		$(LIBC) $(NAME) $(OBJS)
		
all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re:	fclean all

.PHONY: all bonus clean fclean re .c.o