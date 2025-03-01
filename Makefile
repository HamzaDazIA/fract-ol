SRCS = mandatoria/do_fractol2.c mandatoria/do_fractol.c mandatoria/events.c \
	mandatoria/initialization.c mandatoria/main.c mandatoria/parsin.c \
	mandatoria/utils_fonction.c

SRCSB = bonus/do_fractol2.c bonus/do_fractul.c bonus/events.c \
	bonus/initialization.c bonus/main.c bonus/parsin.c bonus/utils_fonction.c

OBJS = ${SRCS:.c=.o}
OBJSB = ${SRCSB:.c=.o}

NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME} ${MLX_FLAGS}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJSB}
	${CC} ${OBJSB} -o ${NAME_BONUS} ${MLX_FLAGS}

${OBJS}: mandatoria/fractol.h
${OBJSB}: bonus/fractol.h

clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: clean 
