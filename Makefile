SRCS = mandatoria/do_fractol2.c mandatoria/do_fractol.c mandatoria/events.c \
	mandatoria/initialization.c mandatoria/main.c mandatoria/parsin.c \
	mandatoria/utils_fonction.c

SRCSB = bonus/check_input_bonus.c bonus/do_relus.c bonus/ft_atoi2_bonus.c \
	bonus/ft_atoi_bonus.c bonus/ft_isdigit_bonus.c bonus/ft_lis_bonus.c \
	bonus/ft_putendl_fd_bonus.c bonus/ft_split.c bonus/ft_strjoin_bonus.c \
	bonus/get_next_line.c bonus/get_next_line_utils.c bonus/main_bonus.c \
	bonus/utili_fonction_bonus.c rules_bonus/ft_push_bonus.c \
	rules_bonus/ft_rev_rotate_bonus.c rules_bonus/ft_rotate_bonus.c \
	rules_bonus/ft_rules_bonus.c rules_bonus/ft_swap_bonus.c \
	rules_bonus/rules_bonus.c rules_bonus/rules_rev_bonus.c

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

.PHONY: all clean fclean re bonus
