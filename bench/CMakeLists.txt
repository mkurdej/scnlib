scn_add_executable(scanf
    main.cpp

    detail/warning.h
    input.h

    boost_qi.cpp
    iostream.cpp
    scn_parse.cpp
    scanf.cpp
    strto.cpp
)

target_link_libraries(scanf
    benchmark
)

set_ide_folder("benchmarks"
    scanf
)

