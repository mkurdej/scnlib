cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.5)

project(libscn
    VERSION     0.1.0
    LANGUAGES   CXX
)
enable_testing()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX "d")

macro(scn_add_executable TARGET args)
    add_executable(${TARGET} ${args})
    set_target_properties(${TARGET} PROPERTIES
        DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    )
    install(TARGETS ${TARGET}
        RUNTIME DESTINATION bin
    )
endmacro()

macro(set_ide_folder args)
    set(folder ${ARGV0})
    foreach(project ${ARGN})
        set_target_properties(${project} PROPERTIES FOLDER ${folder})
    endforeach()
endmacro()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/boost
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/google-benchmark/include
)

set(GCC_OR_CLANG
    "GNU"
    "Clang"
)

if (MSVC)
    add_definitions(
        /DNOMINMAX=1
        #/D_CRT_SECURE_NO_DEPRECATE
        /D_CRT_SECURE_NO_WARNINGS
        #/D_HAS_AUTO_PTR_ETC=0
        #/D_HAS_ITERATOR_DEBUGGING=$<CONFIG:Debug>
        #/D_SCL_SECURE_NO_WARNINGS
        #/D_SECURE_SCL=$<CONFIG:Debug>
    )
    add_compile_options(
        /WX
        /W4
    )
elseif("${CMAKE_CXX_COMPILER_ID}" IN_LIST GCC_OR_CLANG)
    add_compile_options(
        -Werror
        -Wall
        -Wpedantic
    )
endif()

add_subdirectory(thirdparty)
add_subdirectory(bench)
# add_subdirectory(src)
# add_subdirectory(tests)
