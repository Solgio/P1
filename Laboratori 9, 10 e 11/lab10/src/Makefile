LIBS_DIR = ../lib
CC = gcc
FLAGS = -g -O0 -L${LIBS_DIR} -I${LIBS_DIR} -ladvanced -lbasic -lm

ARCHIVES = ${LIBS_DIR}/libbasic.a ${LIBS_DIR}/libadvanced.a

%.o: %.c
	${CC} -g -O0 -o $@ -c $< -Wall

B_HEADERS = ${shell find ${LIBS_DIR}/basic/ -name '*.h'}
B_SOURCES = ${shell find ${LIBS_DIR}/basic/ -name '*.c'}

A_HEADERS = ${shell find ${LIBS_DIR}/advanced/ -name '*.h'}
A_SOURCES = ${shell find ${LIBS_DIR}/advanced/ -name '*.c'}

B_OBJS = ${B_SOURCES:.c=.o}
A_OBJS = ${A_SOURCES:.c=.o}

${LIBS_DIR}/libbasic.a: ${B_HEADERS} ${B_OBJS}
	ar rcs ${LIBS_DIR}/libbasic.a ${B_OBJS}

${LIBS_DIR}/libadvanced.a: ${A_HEADERS} ${A_OBJS}
	ar rcs ${LIBS_DIR}/libadvanced.a ${A_OBJS}

EX_LIST = ${wildcard */}
COMMANDS = ${EX_LIST:%/=%}
EXECS = ${EX_LIST:%/=%.out}

.PHONY: ${COMMANDS} all

${COMMANDS}: % : %.out
all: ${COMMANDS}

.SECONDEXPANSION:
$(EXECS): %.out : ${ARCHIVES} $$(wildcard %/*.c)
	${CC} -o $@ $*/*.c ${FLAGS}

clean:
	find ../ -name '*.o' -delete
	find ../ -name '*.a' -delete
	rm ${EXECS}
