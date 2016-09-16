add_executable(scanf
    scanf.cpp
)

target_link_libraries(scanf
    benchmark
)

set_ide_folder("benchmarks"
    scanf
)

