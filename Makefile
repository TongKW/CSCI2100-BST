CC := g++ 
SRCDIR := src
BIN := bin
${BUILD} := build

all: main

main: ${BIN}/bst.o ${BUILD}/main.o
	${CC} -o main ${BUILD}/main.o ${BIN}/bst.o

${BIN}/bst.o: ${SRCDIR}/bst.cpp 
	${CC} -c -o ${BIN}/bst.o ${SRCDIR}/bst.cpp ${SRCDIR}/merge_sort.cpp

${BUILD}/main.o: ${SRCDIR}/main.cpp
	${CC} -c -o ${BUILD}/main.o ${SRCDIR}/main.cpp

clean:
	${RM} -r ${BUILD}/*

.PHONY: clean