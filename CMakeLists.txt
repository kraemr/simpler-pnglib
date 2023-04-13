

cmake_minimum_required(VERSION 3.0)
project(my_project)
set(CMAKE_CXX_STANDARD 11)

# Set the name and source files for your library
set(LIBRARY_NAME spng_lib)
set(SOURCE_FILES spnglib_read_txt.c globals.c spnglib_read.c spnglib_write_txt.c spnglib_write.c)

# Add a target for your library
add_library(${LIBRARY_NAME} STATIC ${SOURCE_FILES})

# Link your library to the zlib-ng library
#target_link_libraries(${LIBRARY_NAME} zlibstatic)

# Set the library installation directory
install(TARGETS ${LIBRARY_NAME} LIBRARY DESTINATION .)