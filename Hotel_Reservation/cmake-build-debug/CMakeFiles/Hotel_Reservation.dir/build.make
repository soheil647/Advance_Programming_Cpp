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
CMAKE_SOURCE_DIR = /home/sspc/Desktop/AP_Projects/Hotel_Reservation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Hotel_Reservation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hotel_Reservation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hotel_Reservation.dir/flags.make

CMakeFiles/Hotel_Reservation.dir/main.cpp.o: CMakeFiles/Hotel_Reservation.dir/flags.make
CMakeFiles/Hotel_Reservation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hotel_Reservation.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hotel_Reservation.dir/main.cpp.o -c /home/sspc/Desktop/AP_Projects/Hotel_Reservation/main.cpp

CMakeFiles/Hotel_Reservation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hotel_Reservation.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Hotel_Reservation/main.cpp > CMakeFiles/Hotel_Reservation.dir/main.cpp.i

CMakeFiles/Hotel_Reservation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hotel_Reservation.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Hotel_Reservation/main.cpp -o CMakeFiles/Hotel_Reservation.dir/main.cpp.s

CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.o: CMakeFiles/Hotel_Reservation.dir/flags.make
CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.o: ../source/hotel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.o -c /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/hotel.cpp

CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/hotel.cpp > CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.i

CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/hotel.cpp -o CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.s

CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.o: CMakeFiles/Hotel_Reservation.dir/flags.make
CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.o: ../source/reservationSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.o -c /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/reservationSystem.cpp

CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/reservationSystem.cpp > CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.i

CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/reservationSystem.cpp -o CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.s

CMakeFiles/Hotel_Reservation.dir/source/user.cpp.o: CMakeFiles/Hotel_Reservation.dir/flags.make
CMakeFiles/Hotel_Reservation.dir/source/user.cpp.o: ../source/user.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Hotel_Reservation.dir/source/user.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hotel_Reservation.dir/source/user.cpp.o -c /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/user.cpp

CMakeFiles/Hotel_Reservation.dir/source/user.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hotel_Reservation.dir/source/user.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/user.cpp > CMakeFiles/Hotel_Reservation.dir/source/user.cpp.i

CMakeFiles/Hotel_Reservation.dir/source/user.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hotel_Reservation.dir/source/user.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/user.cpp -o CMakeFiles/Hotel_Reservation.dir/source/user.cpp.s

CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.o: CMakeFiles/Hotel_Reservation.dir/flags.make
CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.o: ../source/hotelExceptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.o -c /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/hotelExceptions.cpp

CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/hotelExceptions.cpp > CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.i

CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sspc/Desktop/AP_Projects/Hotel_Reservation/source/hotelExceptions.cpp -o CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.s

# Object files for target Hotel_Reservation
Hotel_Reservation_OBJECTS = \
"CMakeFiles/Hotel_Reservation.dir/main.cpp.o" \
"CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.o" \
"CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.o" \
"CMakeFiles/Hotel_Reservation.dir/source/user.cpp.o" \
"CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.o"

# External object files for target Hotel_Reservation
Hotel_Reservation_EXTERNAL_OBJECTS =

Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/main.cpp.o
Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/source/hotel.cpp.o
Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/source/reservationSystem.cpp.o
Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/source/user.cpp.o
Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/source/hotelExceptions.cpp.o
Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/build.make
Hotel_Reservation: CMakeFiles/Hotel_Reservation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Hotel_Reservation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hotel_Reservation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hotel_Reservation.dir/build: Hotel_Reservation

.PHONY : CMakeFiles/Hotel_Reservation.dir/build

CMakeFiles/Hotel_Reservation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hotel_Reservation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hotel_Reservation.dir/clean

CMakeFiles/Hotel_Reservation.dir/depend:
	cd /home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sspc/Desktop/AP_Projects/Hotel_Reservation /home/sspc/Desktop/AP_Projects/Hotel_Reservation /home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug /home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug /home/sspc/Desktop/AP_Projects/Hotel_Reservation/cmake-build-debug/CMakeFiles/Hotel_Reservation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hotel_Reservation.dir/depend
