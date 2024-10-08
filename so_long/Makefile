NAME = so_long

CC = cc
CFLAGS =  -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
AZUL = \033[1;36m
RESTAURA = \033[0m

SRCS = moves.c moves_auxs.c so_long_utils.c read_map.c game_play.c main.c check_error.c check_error_auxs.c check_lines_error.c check_stuck_error.c check_stuck_error_auxs.c check_content_error.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I. -I$(MLX_DIR) -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(FT_PRINTF_LIB) $(LIBFT_LIB) -o $(NAME) -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
	@clear
	@echo "${AZUL}SOOOOOOOO${RESTAURA} ${AZUL}LOOOOOOOOOOOONG${RESTAURA}"

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@rm -f *.o
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@clear

re: fclean all

.PHONY: all clean fclean re
