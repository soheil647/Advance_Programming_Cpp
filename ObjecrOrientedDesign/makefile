_BUILD_DIR=Object_Files
_SOURCE_DIR=Source
_HEADER_DIR=Header

_CC_EXEC=g++ -std=c++11
CC_FLAGS=-I${Header}/ -c

_CC=${_CC_EXEC} ${CC_FLAGS}

all: Goodreads.out

Goodreads.out: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Google_read.o  ${_BUILD_DIR}/User.o  ${_BUILD_DIR}/Reviews.o  ${_BUILD_DIR}/Books.o  ${_BUILD_DIR}/Authors.o ${_BUILD_DIR}/Follow_edges.o
	${_CC_EXEC} -o Goodreads.out ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Google_read.o  ${_BUILD_DIR}/User.o  ${_BUILD_DIR}/Reviews.o  ${_BUILD_DIR}/Books.o  ${_BUILD_DIR}/Authors.o ${_BUILD_DIR}/Follow_edges.o

${_BUILD_DIR}/Authors.o: ${_SOURCE_DIR}/Authors.cpp ${_HEADER_DIR}/Authors.h
	${_CC} ${_SOURCE_DIR}/Authors.cpp -o ${_BUILD_DIR}/Authors.o

${_BUILD_DIR}/User.o: ${_SOURCE_DIR}/User.cpp ${_HEADER_DIR}/User.h
	${_CC} ${_SOURCE_DIR}/User.cpp -o ${_BUILD_DIR}/User.o

${_BUILD_DIR}/Reviews.o: ${_SOURCE_DIR}/Reviews.cpp ${_HEADER_DIR}/Reviews.h
	${_CC} ${_SOURCE_DIR}/Reviews.cpp -o ${_BUILD_DIR}/Reviews.o

${_BUILD_DIR}/Books.o: ${_SOURCE_DIR}/Books.cpp ${_HEADER_DIR}/Books.h
	${_CC} ${_SOURCE_DIR}/Books.cpp -o ${_BUILD_DIR}/Books.o

${_BUILD_DIR}/Follow_edges.o: ${_SOURCE_DIR}/Follow_edges.cpp ${_HEADER_DIR}/Follow_edges.h
	${_CC} ${_SOURCE_DIR}/Follow_edges.cpp -o ${_BUILD_DIR}/Follow_edges.o

${_BUILD_DIR}/Google_read.o: ${_SOURCE_DIR}/Google_read.cpp ${_HEADER_DIR}/Google_read.h ${_HEADER_DIR}/User.h ${_HEADER_DIR}/Books.h ${_HEADER_DIR}/Authors.h ${_HEADER_DIR}/Reviews.h ${_HEADER_DIR}/Follow_edges.h
	${_CC} ${_SOURCE_DIR}/Google_read.cpp -o ${_BUILD_DIR}/Google_read.o

${_BUILD_DIR}/main.o: ${_SOURCE_DIR}/main.cpp ${_HEADER_DIR}/Google_read.h
	${_CC} ${_SOURCE_DIR}/main.cpp -o ${_BUILD_DIR}/main.o

clean:
	rm ${_BUILD_DIR}/*.o
	rm Goodreads.out
