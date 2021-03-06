NAME = pipex

CC = gcc
C_FLAGS = -Wall -Wextra -Werror

C_FILES = $(wildcard *.c)
O_FILES = $(C_FILES:.c=.o)

LIBFT = libft/libft.a
LIBFT_INC = -L libft -lft
LIBFT_DIR = libft
LIBFT_H = libft/libft.h
LIBFT_REPO = https://github.com/adesgran/libft_extended.git

INCLUDES = -I ${LIBFT_DIR} -I .

.c.o:
		${CC} ${C_FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all: ${LIBFT} ${NAME}

${LIBFT}:
		if [ ! -d "./libft" ]; then git clone ${LIBFT_REPO} libft; fi
		make -C libft

${NAME}: ${O_FILES}
		${CC} ${O_FILES} ${LIBFT_INC} -o ${NAME}

clean:
		rm -r ${O_FILES}
			make clean -C ${LIBFT_DIR}

fclean: clean
		rm -r ${NAME}
			make fclean -C ${LIBFT_DIR}

re: fclean all
