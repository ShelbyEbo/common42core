SRC	=  hexas numbers words ft_printf

SRCS = $(addsuffix .c, ${SRC})

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

RM = rm -f

AR = ar rc

RN = ranlib

OBJS = ${SRCS:.c=.o}

all: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RN) $(NAME)

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	 @$(RM) $(OBJS) $(OBJSB)

fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
