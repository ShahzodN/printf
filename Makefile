NAME	=	libftprintf.a

SOURCES	=	ft_printf.c \
			d_handler.c \
			s_handler.c \
			p_handler.c \
			u_handler.c \
			c_handler.c \
			x_handler.c \
			maker.c \
			parser.c

SRC_DIR	=	src

OBJ_DIR	=	obj

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

HEADER	=	inclides

FLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all: $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)/ft_printf.h
	mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C libft/
	cp libft/libft.a .
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
