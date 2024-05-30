#Makefile
CC = gcc
CFALGS = -std=c99 -Werror
#CPPFLAGS =
#LDFLAGS =
LDLIBS = -lcriterion

SRC = linked_list.c test.c
OBJ = ${SRC:.c=.o}
#DEP = ${SRC:.c=.d}

#h: ${OBJ}

ll: ${OBJ}
	${CC} ${CFALGS} -o $@ $^

%.o: %.c
	${CC} ${CFALGS} -c $< -o $@

test: ${OBJ}
	${CC} ${CFLAGS} ${LDLIBS} ${OBJ} -o test

check: test 
	./test

.PHONY: clean, check, test

clean:
	${RM} ${DEP} ${OBJ} ll test

