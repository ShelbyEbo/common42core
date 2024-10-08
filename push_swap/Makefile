CC = cc

CFLAGS = -Wall -Wextra -Werror

PRINTFSRC = ft_printf

NAME = push_swap

SORTING_DIR = sorting
TURK_DIR = turk_algorithm
LIBFT_DIR = libftaux
OPERATIONS_DIR = operations
STACK_DIR = stack
AR = ar rc

RN = ranlib

SRC =   push_swap.c \
	checks.c \
	$(STACK_DIR)/rules.c \
	$(STACK_DIR)/stack_auxs.c \
	$(TURK_DIR)/operations_of_turk.c \
	$(TURK_DIR)/targets.c \
	$(TURK_DIR)/turk_auxs.c \
	$(SORTING_DIR)/sorting.c \
	$(SORTING_DIR)/sorting_aux.c \
	$(OPERATIONS_DIR)/both.c \
	$(OPERATIONS_DIR)/operations_base.c \
	$(OPERATIONS_DIR)/operations_a.c \
	$(OPERATIONS_DIR)/operations_b.c \
	$(LIBFT_DIR)/auxiliares.c \
	$(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_isdigit.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_substr.c \

LIBFTPRINTF = -L $(PRINTFSRC) -lftprintf
OBJS = $(SRC:.c=.o)
INCDIR = .

DOURADO = \033[38;5;220m
AZULESCURO = \033[1;34m
RESTAURA = \033[0m
VERMELHO = \033[5;31m

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C ${PRINTFSRC}
	@${CC} ${CFLAGS} $^ ${LIBFTPRINTF} -o $@
	@clear
	@echo "Programa bem executado, ${DOURADO}objectos ${DOURADO}criados ${DOURADO}:D"

%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	@make clean -s -C ${PRINTFSRC}
	@rm -f $(OBJS)

fclean: clean
	@make fclean -s -C ${PRINTFSRC}
	@rm -f ${NAME}
	@clear
	@echo "${AZULESCURO}Programa ${AZULESCURO}terminado, ${VERMELHO}ficheiros${RESTAURA} ${VERMELHO}eliminados${RESTAURA} ${VERMELHO}:D${RESTAURA}"

re: fclean all

.PHONY: all clean fclean re
