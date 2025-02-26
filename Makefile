SRCS = do_fractol2.c do_fractul.c events.c initialization.c main.c \
		parsinc.c utils_fonction.c

OBJS = ${SRCS:.c=.o}
NAME = fractol

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c fractol.h
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME} ${MLX_FLAGS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all
