
NAME		= account
SRCS		= Account.cpp tests.cpp
LIBS		= 

SRC_DIR		= .
LIB_DIR		= ./lib
BUILD_DIR	= ./build

CC			= c++
CFLAGS		= -g -Wall -Werror -Wextra -std=c++98
INCLUDE_OBJ	= ${addprefix -I,${LIBS_DIR}}
INCLUDE_SRC	= ${addprefix -L,${LIBS_DIR}}

SRC			= ${addprefix ${BUILD_DIR}/,${SRCS}}
LIBS_DIR	= ${addprefix ${LIB_DIR}/,${LIBS}}
OBJ			= ${SRC:.cpp=.o}
UNAME_S		= $(shell uname -s)

all: ${NAME}

${NAME}: ${BUILD_DIR} ${OBJ}
	$(CC) ${OBJ} ${INCLUDE_SRC} -o ${NAME} $(CFLAGS)

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}/%.o:${SRC_DIR}/%.cpp
	$(CC) ${INCLUDE_OBJ} -c -o $@ $^ $(CFLAGS)

archive: ${BUILD_DIR}
	ar -rc ${NAME}.a ${OBJ}

clean:
	rm -rf ${BUILD_DIR}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME}.a

re: fclean all

.PHONY: clean fclean re archive

