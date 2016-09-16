#include <benchmark/benchmark.h>
#include <cstdio>
#include <sstream>
#include <string>

static const std::string input = "12 132.43 234.5 -43 -34e-3 -4.53e3";

static void BM_scanf_numbers(benchmark::State& state) {
    int i1, i2;
    float f1, f2;
    double d1, d2;
    while(state.KeepRunning()) {
        std::sscanf(input.c_str(), "%d%f%lf%d%f%lf", &i1, &f1, &d1, &i2, &f2, &d2);
    }
}

BENCHMARK(BM_scanf_numbers);

static void BM_stringstream_numbers(benchmark::State& state) {
    std::istringstream is(input);

    int i1, i2;
    float f1, f2;
    double d1, d2;
    while(state.KeepRunning()) {
        is.seekg(0); // rewind
        is >> i1 >> f1 >> d1 >> i2 >> f2 >> d2;
    }
}

BENCHMARK(BM_stringstream_numbers);

BENCHMARK_MAIN()
