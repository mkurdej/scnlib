cmake_minimum_required(VERSION 3.5)
cmake_policy(VERSION 3.5)

project(libscn
    VERSION     0.1.0
    LANGUAGES   CXX
)
enable_testing()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_DEBUG_POSTFIX "d")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/google-benchmark/include
)

if (MSVC)
    add_definitions(
        /DNOMINMAX=1
        #/D_CRT_SECURE_NO_DEPRECATE
        /D_CRT_SECURE_NO_WARNINGS
        /D_HAS_AUTO_PTR_ETC=0
        #/D_HAS_ITERATOR_DEBUGGING=$<CONFIG:Debug>
        #/D_SCL_SECURE_NO_WARNINGS
        #/D_SECURE_SCL=$<CONFIG:Debug>
    )
endif()

add_subdirectory(thirdparty)
add_subdirectory(bench)
# add_subdirectory(src)
# add_subdirectory(tests)

# include(cpack_config)
