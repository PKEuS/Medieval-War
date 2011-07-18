# include the MedievalWar specific macros
#include(${CMAKE_SOURCE_DIR}/cmake/Macros.cmake)

# let CMake know about our additional libraries paths (on Windows and OS X)
#if (WINDOWS)
#    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_SOURCE_DIR}/extlibs/headers")
#    if(COMPILER_GCC)
#        set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/extlibs/libs-mingw")
#        if(ARCH_32BITS)
#            set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/extlibs/bin/x86")
#        else()
#            set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/extlibs/bin/x64")
#        endif()
#    elseif(COMPILER_MSVC)
#        if(ARCH_32BITS)
#            set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86")
#        else()
#            set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x64")
#        endif()
#    endif()
#elseif(MACOSX)
#    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "${CMAKE_SOURCE_DIR}/extlibs/headers")
#    set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${CMAKE_SOURCE_DIR}/extlibs/libs-osx/lib/")
#endif()

# add the MedievalWar sources path
##include_directories(${CMAKE_SOURCE_DIR}/../../src/)

# define the path of our additional CMake modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Modules/")

# set the output directory for sfPhysics libraries
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/../../")

# define the export symbol
#add_definitions(-DSFPHYSICS_EXPORTS)


## ## ##

set(SRCROOT ${CMAKE_SOURCE_DIR}/../../src)

# all source files
set(SRC
    ${SRCROOT}/Main.cpp
    ${SRCROOT}/GameEngine.cpp
    ${SRCROOT}/GameEngine.hpp
    ${SRCROOT}/GameState.cpp
    ${SRCROOT}/GameState.hpp
    ${SRCROOT}/GSIntro.cpp
    ${SRCROOT}/GSIntro.hpp
    ${SRCROOT}/GSMenu.cpp
    ${SRCROOT}/GSMenu.hpp
    ${SRCROOT}/GSSettings.cpp
    ${SRCROOT}/GSSettings.hpp
    ${SRCROOT}/GSCredits.cpp
    ${SRCROOT}/GSCredits.hpp
    ${SRCROOT}/GSSingleplayerGame.cpp
    ${SRCROOT}/GSSingleplayerGame.hpp
    ${SRCROOT}/GSMultiplayerGame.cpp
    ${SRCROOT}/GSMultiplayerGame.hpp
    ${SRCROOT}/GSMapEditor.cpp
    ${SRCROOT}/GSMapEditor.hpp
    ${SRCROOT}/GSError.cpp
    ${SRCROOT}/GSError.hpp
    ${SRCROOT}/Resourcemanager.cpp
    ${SRCROOT}/Resourcemanager.hpp
    ${SRCROOT}/Resourcemanager.inl
    ${SRCROOT}/FileSystem.cpp
    ${SRCROOT}/FileSystem.hpp
    ${SRCROOT}/Settings.cpp
    ${SRCROOT}/Settings.hpp
)

# add executable
add_executable(MedievalWar ${SRC})
target_link_libraries(MedievalWar ${DEPS})

