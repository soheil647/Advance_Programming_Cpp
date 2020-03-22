_CC_EXEC=g++ -std=c++11
CC_FLAGS=-c

_CC=${_CC_EXEC} ${CC_FLAGS}

_BUILD_DIR=Object_Files
_SOURCE_DIR=Source
_HEADER_DIR=Header

all: Goodreads.out

Goodreads.out: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Google_read.o  ${_BUILD_DIR}/User.o  ${_BUILD_DIR}/Reviews.o  ${_BUILD_DIR}/Books.o  ${_BUILD_DIR}/Authors.o
    ${_CC_EXEC}  ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Google_read.o  ${_BUILD_DIR}/User.o  ${_BUILD_DIR}/Reviews.o  ${_BUILD_DIR}/Books.o  ${_BUILD_DIR}/Authors.o -o Goodreads.out

${_BUILD_DIR}/main.o: ${_SOURCE_DIR}/main.cpp ${_HEADER_DIR}/Google_read.h
    ${_CC} ${_SOURCE_DIR}/main.cpp -o main.o

${_BUILD_DIR}/Google_read.o: ${_SOURCE_DIR}/Google_read.cpp ${_HEADER_DIR}/Google_read.h ${_HEADER_DIR}/User.h ${_HEADER_DIR}/Books.h ${_HEADER_DIR}/Authors.h ${_HEADER_DIR}/Reviews.h
    ${_CC} ${_SOURCE_DIR}/Google_read.cpp -o Google_read.o

${_BUILD_DIR}/Authors.o: ${_SOURCE_DIR}/Authors.cpp ${_HEADER_DIR}/Authors.h
    ${_CC} ${_SOURCE_DIR}/Authors.cpp -o Authors.o

${_BUILD_DIR}/User.o: ${_SOURCE_DIR}/User.cpp ${_HEADER_DIR}/User.h
    ${_CC} ${_SOURCE_DIR}/User.cpp -o User.o

${_BUILD_DIR}/Reviews.o: ${_SOURCE_DIR}/Reviews.cpp ${_HEADER_DIR}/Reviews.h
    ${_CC} ${_SOURCE_DIR}/Reviews.cpp -o Reviews.o

${_BUILD_DIR}/Books.o: ${_SOURCE_DIR}/Books.cpp ${_HEADER_DIR}/Books.h
    ${_CC} ${_SOURCE_DIR}/Books.cpp -o Books.o

clean:
    rm ${_BUILD_DIR}/*.o
    rm Goodreads.out
