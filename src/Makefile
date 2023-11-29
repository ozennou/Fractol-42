NAME = fractol

SRCS =  main.c \
		ft_mlx.c \
		event.c \
		utils.c \
		mandel_julia.c \
		mouse.c \
		key.c \
		burning_ship_bonus.c \
		color.c \
		params.c

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror #-fsanitize=address

RM = rm -f

%.o : %.c header.h defines.h
	$(CC) -Imlx -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

bonus : all

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
