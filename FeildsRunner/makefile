_BUILD_DIR=object_files
_SOURCE_DIR=source
_HEADER_DIR=header

_CC_EXEC=g++ -std=c++11 -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
CC_FLAGS=-I${Header}/ -c

_CC=${_CC_EXEC} ${CC_FLAGS}

all: ‫‪FieldRunners

‫‪FieldRunners: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Map.o ${_BUILD_DIR}/MapExceptions.o  ${_BUILD_DIR}/Tower.o  ${_BUILD_DIR}/Enemies.o ${_BUILD_DIR}/rsdl.o
	${_CC_EXEC} -o ‫‪FieldRunners.out ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/Map.o  ${_BUILD_DIR}/User.o  ${_BUILD_DIR}/MapExceptions.o  ${_BUILD_DIR}/Tower.o  ${_BUILD_DIR}/Enemies.o ${_BUILD_DIR}/rsdl.o

${_BUILD_DIR}/Map.o: ${_SOURCE_DIR}/Map.cpp ${_HEADER_DIR}/Tower.h ${_HEADER_DIR}/Enemies.h ${_HEADER_DIR}/MapExceptions.h ${_HEADER_DIR}/rsdl.h
	${_CC} ${_SOURCE_DIR}/Map.cpp -o ${_BUILD_DIR}/Map.o

${_BUILD_DIR}/MapExceptions.o: ${_SOURCE_DIR}/MapExceptions.cpp ${_HEADER_DIR}/MapExceptions.h
	${_CC} ${_SOURCE_DIR}/MapExceptions.cpp -o ${_BUILD_DIR}/MapExceptions.o

${_BUILD_DIR}/Tower.o: ${_SOURCE_DIR}/Tower.cpp ${_HEADER_DIR}/Tower.h ${_HEADER_DIR}/Enemies.h ${_HEADER_DIR}/MapExceptions.h ${_HEADER_DIR}/rsdl.h
	${_CC} ${_SOURCE_DIR}/Reviews.cpp -o ${_BUILD_DIR}/Reviews.o

${_BUILD_DIR}/Enemies.o: ${_SOURCE_DIR}/Enemies.cpp ${_HEADER_DIR}/Enemies.h ${_HEADER_DIR}/rsdl.h
	${_CC} ${_SOURCE_DIR}/Enemies.cpp -o ${_BUILD_DIR}/Enemies.o

${_BUILD_DIR}/rsdl.o: ${_SOURCE_DIR}/rsdl.cpp ${_HEADER_DIR}/rsdl.h
	${_CC} ${_SOURCE_DIR}/rsdl.cpp -o ${_BUILD_DIR}/rsdl.o

${_BUILD_DIR}/main.o: ${_SOURCE_DIR}/main.cpp ${_HEADER_DIR}/Map.h
	${_CC} ${_SOURCE_DIR}/main.cpp -o ${_BUILD_DIR}/main.o

clean:
	rm ${_BUILD_DIR}/*.o
	rm ‫‪FieldRunners.out
