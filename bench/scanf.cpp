#include <benchmark/benchmark.h>
#include <cstdio>
#include <string>

static void BM_scanf_numbers(benchmark::State& state) {
    static const std::string s = "12 132.43 234.5 -43 -34e-3 -4.53e3";
    int i1, i2;
    float f1, f2;
    double d1, d2;
    while(state.KeepRunning()) {
        std::sscanf(s.c_str(), "%d%f%lf%d%f%lf", &i1, &f1, &d1, &i2, &f2, &d2);
    }
}

BENCHMARK(BM_scanf_numbers);

BENCHMARK_MAIN()
