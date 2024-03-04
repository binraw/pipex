NAME = pipex


SRCS_FILE = main.c utils.c error.c


CC = cc
MD = mkdir -p
CFLAGS = -Wall -Wextra -Werror -g


DIR_SRC = src/
DIR_OBJ = .object/


LIBFT = ./lib/libft/libft.a

OBJS = $(patsubst %.c, ${DIR_OBJ}%.o, ${SRCS})
SRCS = $(addprefix ${DIR_SRC},${SRCS_FILE})
OBJS_BONUS = $(patsubst %.c, ${DIR_OBJ_BONUS}%.o, ${SRCS_BONUS})


RM = rm -Rf

all: libft ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)


${DIR_OBJ}%.o: %.c ${DIR_SRC}/pipex.h Makefile
	mkdir -p $(shell dirname $@)
	$(CC) ${CFLAGS} -c $< -o $@


libft: 
	${MAKE} -C ./lib/libft all

clean:
	${MAKE} -C ./lib/libft clean
	${RM} ${DIR_OBJ}

fclean: clean
	${MAKE} -C ./lib/libft fclean
	${RM} ${NAME}

re: fclean all



.PHONY: all clean fclean re 