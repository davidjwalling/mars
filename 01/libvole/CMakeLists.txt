cmake_minimum_required(VERSION 3.10)
 
project(libvole)
 
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_definitions(-D_WINDLL)
endif()
 
set(PROTO_SRCS
    VoleDriver.cpp
)
 
set(PROTO_HDRS
    VoleAPI.h
    VoleDriver.h
)
 
add_library(libvole SHARED ${PROTO_SRCS})
 
set_target_properties(libvole PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
set_target_properties(libvole PROPERTIES PUBLIC_HEADER "${PROTO_HDRS}")
 
target_include_directories(libvole INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
 
install(TARGETS libvole EXPORT HControl
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    RUNTIME       DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
 
install(EXPORT libvole
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libvole
    FILE LibvoleConfig.cmake
)
 
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    install(FILES libvole
        $<TARGET_PDB_FILE:libvole> DESTINATION ${CMAKE_INSTALL_BINDIR} OPTIONAL
    )
endif()