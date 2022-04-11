cmake_minimum_required(VERSION 3.10)
 
project(libmars)
 
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_definitions(-D_WINDLL)
endif()
 
set(PROTO_SRCS
    driver.cpp
)
 
set(PROTO_HDRS
    api.h
    driver.h
)
 
add_library(libmars SHARED ${PROTO_SRCS})
 
set_target_properties(libmars PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
set_target_properties(libmars PROPERTIES PUBLIC_HEADER "${PROTO_HDRS}")
 
target_include_directories(libmars INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
 
install(TARGETS libmars EXPORT mars
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    RUNTIME       DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
 
install(EXPORT mars
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mars
    FILE MarsConfig.cmake
)
 
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    install(FILES libmars
        $<TARGET_PDB_FILE:libmars> DESTINATION ${CMAKE_INSTALL_BINDIR} OPTIONAL
    )
endif()
