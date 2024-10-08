CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTFSRC = ft_printf

CLIENT = client
SERVER = server

NAME = prog

SRC = auxiliares.c \
      personalizar.c
CLIENT_SRC = client.c
SERVER_SRC = server.c

LIBFTPRINTF = $(PRINTFSRC)/libftprintf.a
OBJS = $(SRC:.c=.o)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

VERDE = \033[1;32m
VERMELHO = \033[5;31m
AZUL = \033[1;36m
RESTAURA = \033[0m

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(LIBFTPRINTF):
	@make -s -C $(PRINTFSRC)

$(CLIENT): $(CLIENT_OBJS) $(OBJS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(OBJS) $(LIBFTPRINTF) -o $(CLIENT)
	@clear

$(SERVER): $(SERVER_OBJS) $(OBJS) $(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(OBJS) $(LIBFTPRINTF) -o $(SERVER)
	@clear
	@echo "${VERDE}Server e Client criados com sucesso!${RESTAURA}"

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@make clean -s -C ${PRINTFSRC}
	@rm -f $(OBJS) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	@make fclean -s -C ${PRINTFSRC}
	@rm -f $(CLIENT) $(SERVER)
	@clear
	@echo "${VERMELHO}Executáveis eliminados!${RESTAURA}"

re: fclean all

.PHONY: all clean fclean re

