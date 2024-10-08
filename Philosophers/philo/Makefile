CC = cc
CFLAGS = -Wall -Wextra -Werror

AUXILIARS_DIR = auxiliars

NAME = philo

SOURCES = main.c \
		  check_error.c\
		  philosophers_routine.c\
		  list_rules.c\
		  philo_status.c\
		  inits.c\
		  routine_auxiliars.c\
          ${AUXILIARS_DIR}/ft_atoi.c \
          ${AUXILIARS_DIR}/ft_isdigit.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@clear
	@echo "Philosophers compiled successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f ${NAME}
	@clear
	@echo "Philosophers neutralized!"

re: fclean all

.PHONY: all clean fclean re