cmake_minimum_required(VERSION 3.10)
 
project(vole)
 
add_executable(vole main.cpp)
 
target_link_libraries(vole libvole)
 
install(TARGETS vole
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)