cmake_minimum_required(VERSION 3.10)
 
project(mars)
 
add_executable(mars main.cpp)
 
target_link_libraries(mars libmars)

install(TARGETS mars
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
