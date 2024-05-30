#Makefile
CC = gcc
CFALGS = -std=c99 -Werror
#CPPFLAGS =
#LDFLAGS =
#LDLIBS =

SRC = linked_list.c test.c
OBJ = ${SRC:.c=.o}
#DEP = ${SRC:.c=.d}

#h: ${OBJ}

ll: ${OBJ}
	${CC} ${CFALGS} -o $@ $^

%.o: %.c
	${CC} ${CFALGS} -c $< -o $@

.PHONY: clean

clean:
	${RM} ${DEP} ${OBJ} ll
