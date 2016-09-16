# add_subdirectory(boost)

if (MSVC)
    add_compile_options(
        /wd4459 # declaration of 'variable' hides global declaration
        /wd4722 # destructor never returns, potential memory leak
    )
endif()

add_subdirectory(google-benchmark)
