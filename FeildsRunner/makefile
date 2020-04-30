_BUILD_DIR=object_files
_SOURCE_DIR=source
_HEADER_DIR=header

_CC_EXEC=g++
CC_FLAGS=-c -std=c++11
_SDL= -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

_CC=${_CC_EXEC} ${CC_FLAGS}

all:‫‪FieldRunners.out

‫‪FieldRunners.out: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Map.o ${_BUILD_DIR}/MapExceptions.o  ${_BUILD_DIR}/Tower.o  ${_BUILD_DIR}/Enemies.o ${_BUILD_DIR}/rsdl.o
	${_CC_EXEC} ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Map.o ${_BUILD_DIR}/MapExceptions.o  ${_BUILD_DIR}/Tower.o  ${_BUILD_DIR}/Enemies.o ${_BUILD_DIR}/rsdl.o ${_SDL} -o ‫‪FieldRunners.out

${_BUILD_DIR}/main.o: ${_SOURCE_DIR}/main.cpp ${_BUILD_DIR}/Map.o
	${_CC} ${_SOURCE_DIR}/main.cpp -o ${_BUILD_DIR}/main.o

${_BUILD_DIR}/Map.o: ${_SOURCE_DIR}/Map.cpp ${_HEADER_DIR}/Map.h ${_BUILD_DIR}/MapExceptions.o  ${_BUILD_DIR}/Tower.o  ${_BUILD_DIR}/Enemies.o ${_BUILD_DIR}/rsdl.o
	${_CC} ${_SOURCE_DIR}/Map.cpp -o ${_BUILD_DIR}/Map.o

${_BUILD_DIR}/MapExceptions.o: ${_SOURCE_DIR}/MapExceptions.cpp ${_HEADER_DIR}/MapExceptions.h
	${_CC} ${_SOURCE_DIR}/MapExceptions.cpp -o ${_BUILD_DIR}/MapExceptions.o

${_BUILD_DIR}/Tower.o: ${_SOURCE_DIR}/Tower.cpp ${_BUILD_DIR}/MapExceptions.o ${_BUILD_DIR}/Enemies.o ${_BUILD_DIR}/rsdl.o
	${_CC} ${_SOURCE_DIR}/Tower.cpp -o ${_BUILD_DIR}/Tower.o

${_BUILD_DIR}/Enemies.o: ${_SOURCE_DIR}/Enemies.cpp ${_HEADER_DIR}/Enemies.h ${_BUILD_DIR}/rsdl.o
	${_CC} ${_SOURCE_DIR}/Enemies.cpp -o ${_BUILD_DIR}/Enemies.o

${_BUILD_DIR}/rsdl.o: ${_SOURCE_DIR}/rsdl.cpp ${_HEADER_DIR}/rsdl.hpp
	${_CC} ${_SOURCE_DIR}/rsdl.cpp -o ${_BUILD_DIR}/rsdl.o
clean:
	rm ${_BUILD_DIR}/*.o
	rm ‫‪FieldRunners.out
