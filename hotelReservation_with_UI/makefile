_BUILD_DIR=object_files
_SOURCE_DIR=source
_HEADER_DIR=header

_CC_EXEC=g++
CC_FLAGS=-c -std=c++11

_CC=${_CC_EXEC} ${CC_FLAGS}

all:utrip.out

utrip.out: ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/reservationSystem.o ${_BUILD_DIR}/hotel.o ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/user.o ${_BUILD_DIR}/room.o ${_BUILD_DIR}/userReservation.o ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/cityFilter.o ${_BUILD_DIR}/starFilter.o ${_BUILD_DIR}/costFilter.o ${_BUILD_DIR}/roomFilter.o ${_BUILD_DIR}/defaultPriceFilter.o ${_BUILD_DIR}/ratings.o ${_BUILD_DIR}/ratingWeights.o $(_BUILD_DIR)/response.o $(_BUILD_DIR)/server.o $(_BUILD_DIR)/handlers.o $(_BUILD_DIR)/request.o $(_BUILD_DIR)/utilities.o $(_BUILD_DIR)/route.o
	${_CC_EXEC} ${_BUILD_DIR}/main.o  ${_BUILD_DIR}/reservationSystem.o ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/user.o ${_BUILD_DIR}/hotel.o ${_BUILD_DIR}/room.o ${_BUILD_DIR}/userReservation.o ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/cityFilter.o ${_BUILD_DIR}/starFilter.o ${_BUILD_DIR}/costFilter.o ${_BUILD_DIR}/roomFilter.o ${_BUILD_DIR}/defaultPriceFilter.o ${_BUILD_DIR}/ratings.o ${_BUILD_DIR}/ratingWeights.o $(_BUILD_DIR)/response.o $(_BUILD_DIR)/server.o $(_BUILD_DIR)/handlers.o $(_BUILD_DIR)/request.o $(_BUILD_DIR)/utilities.o $(_BUILD_DIR)/route.o -o utrip.out

${_BUILD_DIR}/main.o: main.cpp ${_BUILD_DIR}/reservationSystem.o
	${_CC} main.cpp -o ${_BUILD_DIR}/main.o

${_BUILD_DIR}/reservationSystem.o: ${_SOURCE_DIR}/reservationSystem.cpp ${_HEADER_DIR}/reservationSystem.hpp ${_HEADER_DIR}/user.hpp ${_HEADER_DIR}/hotel.hpp ${_HEADER_DIR}/hotelExceptions.hpp ${_BUILD_DIR}/hotel.o ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/user.o
	${_CC} ${_SOURCE_DIR}/reservationSystem.cpp -o ${_BUILD_DIR}/reservationSystem.o

${_BUILD_DIR}/hotel.o: ${_SOURCE_DIR}/hotel.cpp ${_HEADER_DIR}/hotel.hpp ${_HEADER_DIR}/hotelExceptions.hpp ${_HEADER_DIR}/room.hpp ${_HEADER_DIR}/ratings.hpp ${_BUILD_DIR}/hotelExceptions.o ${_BUILD_DIR}/room.o ${_BUILD_DIR}/ratings.o ${_BUILD_DIR}/hotelExceptions.o
	${_CC} ${_SOURCE_DIR}/hotel.cpp -o ${_BUILD_DIR}/hotel.o

${_BUILD_DIR}/user.o: ${_SOURCE_DIR}/user.cpp ${_HEADER_DIR}/user.hpp ${_HEADER_DIR}/userReservation.hpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/ratingWeights.hpp ${_BUILD_DIR}/userReservation.o ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/ratingWeights.o
	${_CC} ${_SOURCE_DIR}/user.cpp -o ${_BUILD_DIR}/user.o ${_BUILD_DIR}/ratingWeights.o

${_BUILD_DIR}/hotelExceptions.o: ${_SOURCE_DIR}/hotelExceptions.cpp ${_HEADER_DIR}/hotelExceptions.hpp
	${_CC} ${_SOURCE_DIR}/hotelExceptions.cpp -o ${_BUILD_DIR}/hotelExceptions.o

${_BUILD_DIR}/room.o: ${_SOURCE_DIR}/room.cpp ${_HEADER_DIR}/room.hpp
	${_CC} ${_SOURCE_DIR}/room.cpp -o ${_BUILD_DIR}/room.o

${_BUILD_DIR}/userReservation.o: ${_SOURCE_DIR}/userReservation.cpp ${_HEADER_DIR}/userReservation.hpp ${_HEADER_DIR}/room.hpp ${_BUILD_DIR}/room.o
	${_CC} ${_SOURCE_DIR}/userReservation.cpp -o ${_BUILD_DIR}/userReservation.o

${_BUILD_DIR}/filter.o: ${_SOURCE_DIR}/filter.cpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/hotel.hpp ${_BUILD_DIR}/hotel.o
	${_CC} ${_SOURCE_DIR}/filter.cpp -o ${_BUILD_DIR}/filter.o

${_BUILD_DIR}/cityFilter.o: ${_SOURCE_DIR}/cityFilter.cpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/hotel.hpp ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/hotel.o
	${_CC} ${_SOURCE_DIR}/cityFilter.cpp -o ${_BUILD_DIR}/cityFilter.o

${_BUILD_DIR}/starFilter.o: ${_SOURCE_DIR}/starFilter.cpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/hotel.hpp ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/hotel.o
	${_CC} ${_SOURCE_DIR}/starFilter.cpp -o ${_BUILD_DIR}/starFilter.o

${_BUILD_DIR}/costFilter.o: ${_SOURCE_DIR}/costFilter.cpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/hotel.hpp ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/hotel.o
	${_CC} ${_SOURCE_DIR}/costFilter.cpp -o ${_BUILD_DIR}/costFilter.o

${_BUILD_DIR}/roomFilter.o: ${_SOURCE_DIR}/roomFilter.cpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/hotel.hpp ${_BUILD_DIR}/filter.o ${_BUILD_DIR}/hotel.o
	${_CC} ${_SOURCE_DIR}/roomFilter.cpp -o ${_BUILD_DIR}/roomFilter.o

${_BUILD_DIR}/defaultPriceFilter.o: ${_SOURCE_DIR}/defaultPriceFilter.cpp ${_HEADER_DIR}/filter.hpp ${_HEADER_DIR}/hotel.hpp ${_HEADER_DIR}/userReservation.hpp
	${_CC} ${_SOURCE_DIR}/defaultPriceFilter.cpp -o ${_BUILD_DIR}/defaultPriceFilter.o

${_BUILD_DIR}/ratings.o: ${_SOURCE_DIR}/ratings.cpp ${_HEADER_DIR}/ratingWeights.hpp ${_BUILD_DIR}/ratingWeights.o
	${_CC} ${_SOURCE_DIR}/ratings.cpp -o ${_BUILD_DIR}/ratings.o

${_BUILD_DIR}/ratingWeights.o: ${_SOURCE_DIR}/ratingWeights.cpp
	${_CC} ${_SOURCE_DIR}/ratingWeights.cpp -o ${_BUILD_DIR}/ratingWeights.o

$(_BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(_CC) utils/response.cpp -o $(_BUILD_DIR)/response.o

$(_BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(_CC) utils/request.cpp -o $(_BUILD_DIR)/request.o

$(_BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(_CC) utils/utilities.cpp -o $(_BUILD_DIR)/utilities.o

$(_BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(_CC) server/server.cpp -o $(_BUILD_DIR)/server.o

$(_BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(_CC) server/route.cpp -o $(_BUILD_DIR)/route.o

$(_BUILD_DIR)/handlers.o: Response/handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(_CC) Response/handlers.cpp -o $(_BUILD_DIR)/handlers.o

clean:
	rm ${_BUILD_DIR}/*.o
	rm utrip.out


