# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sspc/Apps/clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sspc/Apps/clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Smart_Hotel_Reservation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Smart_Hotel_Reservation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Smart_Hotel_Reservation.dir/flags.make

CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/main.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/main.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/main.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.o: ../source/hotel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/hotel.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/hotel.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/hotel.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.o: ../source/reservationSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/reservationSystem.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/reservationSystem.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/reservationSystem.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.o: ../source/user.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/user.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/user.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/user.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.o: ../source/hotelExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/hotelExceptions.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/hotelExceptions.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/hotelExceptions.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.o: ../source/room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/room.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/room.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/room.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.o: ../source/userReservation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/userReservation.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/userReservation.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/userReservation.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.o: ../source/filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/filter.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/filter.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/filter.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.o: ../source/cityFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/cityFilter.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/cityFilter.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/cityFilter.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.o: ../source/starFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/starFilter.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/starFilter.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/starFilter.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.o: ../source/costFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/costFilter.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/costFilter.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/costFilter.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.o: ../source/roomFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/roomFilter.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/roomFilter.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/roomFilter.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.o: ../source/defaultPriceFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/defaultPriceFilter.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/defaultPriceFilter.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/defaultPriceFilter.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.o: ../source/ratings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/ratings.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/ratings.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/ratings.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.o: ../source/ratingWeights.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/ratingWeights.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/ratingWeights.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/source/ratingWeights.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.s

CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.o: CMakeFiles/Smart_Hotel_Reservation.dir/flags.make
CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.o -c /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/test.cpp

CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/test.cpp > CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.i

CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/test.cpp -o CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.s

# Object files for target Smart_Hotel_Reservation
Smart_Hotel_Reservation_OBJECTS = \
"CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.o" \
"CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.o"

# External object files for target Smart_Hotel_Reservation
Smart_Hotel_Reservation_EXTERNAL_OBJECTS =

Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/main.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/hotel.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/reservationSystem.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/user.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/hotelExceptions.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/room.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/userReservation.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/filter.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/cityFilter.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/starFilter.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/costFilter.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/roomFilter.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/defaultPriceFilter.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/ratings.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/source/ratingWeights.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/test.cpp.o
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/build.make
Smart_Hotel_Reservation: CMakeFiles/Smart_Hotel_Reservation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable Smart_Hotel_Reservation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Smart_Hotel_Reservation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Smart_Hotel_Reservation.dir/build: Smart_Hotel_Reservation

.PHONY : CMakeFiles/Smart_Hotel_Reservation.dir/build

CMakeFiles/Smart_Hotel_Reservation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Smart_Hotel_Reservation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Smart_Hotel_Reservation.dir/clean

CMakeFiles/Smart_Hotel_Reservation.dir/depend:
	cd /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug /home/sspc/Desktop/AP_Projects/Smart_Hotel_Reservation/cmake-build-debug/CMakeFiles/Smart_Hotel_Reservation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Smart_Hotel_Reservation.dir/depend

