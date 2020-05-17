_BUILD_DIR=object_files
_SOURCE_DIR=source
_HEADER_DIR=header

_CC_EXEC=g++
CC_FLAGS=-c -std=c++11

_CC=${_CC_EXEC} ${CC_FLAGS}

all:utrip.out

utrip.out: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/reservationSystem.o ${_BUILD_DIR}/hotel.o ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/user.o
	${_CC_EXEC} ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/reservationSystem.o ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/user.o ${_BUILD_DIR}/hotel.o -o utrip.out

${_BUILD_DIR}/main.o: main.cpp ${_BUILD_DIR}/reservationSystem.o
	${_CC} main.cpp -o ${_BUILD_DIR}/main.o

${_BUILD_DIR}/reservationSystem.o: ${_SOURCE_DIR}/reservationSystem.cpp ${_BUILD_DIR}/hotel.o ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/user.o
	${_CC} ${_SOURCE_DIR}/reservationSystem.cpp -o ${_BUILD_DIR}/reservationSystem.o

${_BUILD_DIR}/hotel.o: ${_SOURCE_DIR}/hotel.cpp ${_BUILD_DIR}/hotelExceptions.o
	${_CC} ${_SOURCE_DIR}/hotel.cpp -o ${_BUILD_DIR}/hotel.o

${_BUILD_DIR}/user.o: ${_SOURCE_DIR}/user.cpp
	${_CC} ${_SOURCE_DIR}/user.cpp -o ${_BUILD_DIR}/user.o

${_BUILD_DIR}/hotelExceptions.o: ${_SOURCE_DIR}/hotelExceptions.cpp
	${_CC} ${_SOURCE_DIR}/hotelExceptions.cpp -o ${_BUILD_DIR}/hotelExceptions.o
clean:
	rm ${_BUILD_DIR}/*.o
	rm utrip.out


