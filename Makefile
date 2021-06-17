NAME	=	libftprintf.a

SOURCES	=	ft_printf.c \
			d_handler.c \
			s_handler.c \
			p_handler.c \
			u_handler.c \
			c_handler.c \
			x_handler.c \
			maker.c \
			parser.c \
			additional.c

SRCS	=	$(addprefix $(SRC_DIR)/, $(SOURCES))

SRC_DIR	=	src

OBJ_DIR	=	obj

OBJS	=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

HEADER	=	includes

FLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

debug:
	gcc $(FLAGS) -g main.c $(SRCS) -L. -lft
	./a.out | cat -e
