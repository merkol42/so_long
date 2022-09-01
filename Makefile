NAME			= solong.a
B_NAME			= solong_bonus.a
CC				= gcc
APP				= Pacman
CFLAGS			= -Wall -Werror -Wextra
FILES			= $(wildcard src/mandatory/*.c)
B_FILES			= $(wildcard src/bonus/*.c)
OBJ				= $(FILES:%.c=%.o)
B_OBJ			= $(B_FILES:%.c=%.o)
LIBFT			= src/libft/libft.a
GETNEXT			= src/get_next_line/getnextline.a
LINK			= -framework OpenGL -framework AppKit -L./mlx -lmlx

all: make-diff run clean

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

$(B_NAME): $(B_OBJ)
	@ar -rcs $(B_NAME) $(B_OBJ)

make-diff:
	@make -C mlx
	@make -C src/libft
	@make -C src/get_next_line

run: $(NAME)
	$(CC) -o $(APP) $(FILES) $(LIBFT) $(GETNEXT) $(LINK)
	@echo "Pacman Oluşturuldu"

bonus: make-diff
	$(CC) -o Pacman_Bonus $(B_FILES) $(LIBFT) $(GETNEXT) $(LINK)
	@echo "Pacman_Bonus Oluşturuldu"

norm:
	@echo "----------------------------------------------------"
	norminette ./src/mandatory/*.c
	@echo "----------------------------------------------------"
	norminette ./src/bonus/*.c

clean:
	@rm -f src/mandatory/*.o
	@rm -f src/bonus/*.o
	@rm -f src/libft/*.o
	@rm -f src/get_next_line/*.o

fclean: clean
	@rm -f solong.a pacman Pacman_Bonus
	@rm -f src/libft/libft.a
	@rm -f src/get_next_line/getnextline.a

re : fclean all
	@rm -f *.o

.PHONY: all bonus clean fclean re make-diff run norm

