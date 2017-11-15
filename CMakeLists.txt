cmake_minimum_required(VERSION 2.6)
project (Tutorial)

option(USE_MYMATH
    "Use tutorial provided math implementation"
    ON)

# The version number
set( Tutorial_VERSION_MAJOR 1 )
set( Tutorial_VERSION_MINOR 0 )

# Configure a header file to pass some of the Cmake settings to the source
# code

configure_file(
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    )

# add the binary directory tree to the search path for include files so that
# we will find Tutorial.h

include_directories("${PROJECT_BINARY_DIR}")


# add the MathFunctions library?
if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set( EXTRA_LIBS ${EXTRA_LIBS} MathFunctions )
endif(USE_MYMATH)


# add the executable
add_executable(Tutorial tutorial.cxx)
target_link_libraries(Tutorial MathFunctions)

