add_executable(scanf
    main.cpp

    boost_qi.cpp
    iostream.cpp
    scanf.cpp
)

target_link_libraries(scanf
    benchmark
)

set_ide_folder("benchmarks"
    scanf
)

