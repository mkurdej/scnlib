set_ide_folder("thirdparty/google-benchmark"
    benchmark
)

set_ide_folder("thirdparty/google-benchmark/benchmarks"
    basic_benchmark
    complexity_benchmark
    options_benchmark
)

set_ide_folder("thirdparty/google-benchmark/tests"
    output_test_helper

    cxx03
    diagnostics_test
    donotoptimize_test
    fixture_test
    map_test
    multiple_ranges_test
    register_benchmark_test
    reporter_output_test
    skip_with_error_test
)

set_ide_folder("thirdparty/google-benchmark/tests/filter"
    filter_regex_all
    filter_regex_begin
    filter_regex_begin2
    filter_regex_blank
    filter_regex_end
    filter_regex_none
    filter_regex_wildcard
    filter_simple
    filter_suffix
)

add_subdirectory(google-benchmark)
