scn_add_executable(scanf
    main.cpp

    ${CMAKE_SOURCE_DIR}/include/scn/detail/warning.h
    input.h

    ato.cpp
    boost_lexical_cast.cpp
    boost_qi.cpp
    iostream.cpp
    scn_parse.cpp
    scanf.cpp
    sto.cpp
    strto.cpp
)

target_link_libraries(scanf
    benchmark
)

set_ide_folder("benchmarks"
    scanf
)

