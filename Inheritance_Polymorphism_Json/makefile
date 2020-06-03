_BUILD_DIR=object_files
_SOURCE_DIR=source
_HEADER_DIR=header

_CC_EXEC=g++
CC_FLAGS=-c -std=c++11

_CC=${_CC_EXEC} ${CC_FLAGS}

all:1.out

1.out: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/JsonBuilder.o ${_BUILD_DIR}/JsonElement.o ${_BUILD_DIR}/JsonString.o ${_BUILD_DIR}/JsonInt.o ${_BUILD_DIR}/JsonObject.o ${_BUILD_DIR}/JsonArray.o
	${_CC_EXEC} ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/JsonBuilder.o ${_BUILD_DIR}/JsonElement.o  ${_BUILD_DIR}/JsonString.o ${_BUILD_DIR}/JsonInt.o ${_BUILD_DIR}/JsonObject.o ${_BUILD_DIR}/JsonArray.o -o 1.out

${_BUILD_DIR}/main.o: main.cpp JsonBuilder.hpp ${_BUILD_DIR}/JsonBuilder.o
	${_CC} main.cpp -o ${_BUILD_DIR}/main.o

${_BUILD_DIR}/JsonBuilder.o: ${_SOURCE_DIR}/JsonBuilder.cpp JsonBuilder.hpp ${_BUILD_DIR}/JsonElement.o  ${_BUILD_DIR}/JsonString.o ${_BUILD_DIR}/JsonInt.o ${_BUILD_DIR}/JsonObject.o
	${_CC} ${_SOURCE_DIR}/JsonBuilder.cpp -o ${_BUILD_DIR}/JsonBuilder.o

${_BUILD_DIR}/JsonElement.o: ${_SOURCE_DIR}/JsonElement.cpp ${_HEADER_DIR}/JsonElement.hpp
	${_CC} ${_SOURCE_DIR}/JsonElement.cpp -o ${_BUILD_DIR}/JsonElement.o

${_BUILD_DIR}/JsonString.o: ${_SOURCE_DIR}/JsonString.cpp ${_HEADER_DIR}/JsonString.hpp ${_BUILD_DIR}/JsonElement.o
	${_CC} ${_SOURCE_DIR}/JsonString.cpp -o ${_BUILD_DIR}/JsonString.o

${_BUILD_DIR}/JsonInt.o: ${_SOURCE_DIR}/JsonInt.cpp ${_HEADER_DIR}/JsonInt.hpp ${_BUILD_DIR}/JsonElement.o
	${_CC} ${_SOURCE_DIR}/JsonInt.cpp -o ${_BUILD_DIR}/JsonInt.o

${_BUILD_DIR}/JsonObject.o: ${_SOURCE_DIR}/JsonObject.cpp ${_HEADER_DIR}/JsonObject.hpp ${_BUILD_DIR}/JsonElement.o ${_BUILD_DIR}/JsonInt.o ${_BUILD_DIR}/JsonString.o ${_BUILD_DIR}/JsonArray.o
	${_CC} ${_SOURCE_DIR}/JsonObject.cpp -o ${_BUILD_DIR}/JsonObject.o

${_BUILD_DIR}/JsonArray.o: ${_SOURCE_DIR}/JsonArray.cpp ${_HEADER_DIR}/JsonArray.hpp ${_BUILD_DIR}/JsonElement.o ${_BUILD_DIR}/JsonInt.o ${_BUILD_DIR}/JsonString.o
	${_CC} ${_SOURCE_DIR}/JsonArray.cpp -o ${_BUILD_DIR}/JsonArray.o

clean:
	rm ${_BUILD_DIR}/*.o
	rm 1.out
