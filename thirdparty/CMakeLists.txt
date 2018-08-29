# add_subdirectory(boost)

if(MSVC)
    add_compile_options(
        /wd4459 # declaration of 'variable' hides global declaration
        /wd4722 # destructor never returns, potential memory leak
    )
endif()

option(BENCHMARK_ENABLE_TESTING "Enable testing of the benchmark library." OFF)
add_subdirectory(google-benchmark)
