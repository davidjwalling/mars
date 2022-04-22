cmake_minimum_required(VERSION 3.10)

project(MARS)

set(CMAKE_CXX_STANDARD 14)
 
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
	add_definitions(
        -D_WIN32_WINNT=0x0601
        -DNOMINMAX
        -DVC_EXTRALEAN
        -DWIN32_LEAN_AND_MEAN
        -D_CRT_SECURE_NO_WARNINGS
        -D_SCL_SECURE_NO_WARNINGS
        -D_WINSOCK_DEPRECATED_NO_WARNINGS
    )
    set(CMAKE_PDB_OUTPUT_DIRECTORY "${CMAKE_INSTALL_BINDIR}")
endif()
 
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    include(GNUInstallDirs)

    add_compile_options(
        -fvisibility=hidden
        -Wno-deprecated-declarations
    )
endif()
 
add_subdirectory(libmars)
add_subdirectory(mars)
