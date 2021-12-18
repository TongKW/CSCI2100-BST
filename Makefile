CC := g++
SRCDIR := src
BIN := bin
BUILD := build

all: main

main: ${SRCDIR}/bst.cpp ${SRCDIR}/main.cpp ${SRCDIR}/merge_sort.cpp
	${CC} -o main ${SRCDIR}/bst.cpp ${SRCDIR}/main.cpp ${SRCDIR}/merge_sort.cpp

clean:
	${RM} main

.PHONY: clean