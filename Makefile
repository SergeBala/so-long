NAME = so_long
CHECKER = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT_DIR = ./libft
MLX_DIR = ./mlx
FT_PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a
SRC_DIR = ./src
SRC_BONUS_DIR = ./src_bonus
INC_DIR = ./include
OBJ_DIR = ./obj
OBJ_BONUS_DIR = ./obj_bonus
SRC_FILES = parser.c validation_utils.c validation_utils_2.c validation_utils_3.c utils_4.c game_so_long.c\
			mlx_utils.c moves.c 
			
SRC_BONUS_FILES = parser_bonus.c\
			
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS_FILES = $(SRC_BONUS_FILES:%.c=$(OBJ_BONUS_DIR)/%.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ_FILES) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/solong.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(CHECKER): $(OBJ_BONUS_FILES) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_BONUS_FILES) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(INC_DIR)/solong_bonus.h | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@	

FORCE:

$(LIBFT): FORCE
	make -C $(LIBFT_DIR)

$(FT_PRINTF): FORCE
	make -C $(FT_PRINTF_DIR)	

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir -p $(OBJ_BONUS_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

bonus_clean:
	rm -rf $(OBJ_BONUS_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

bonus_fclean: bonus_clean
	rm -f $(CHECKER)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus_clean bonus_fclean