#include "input.h"
#include <benchmark/benchmark.h>
#include <cstdio>
#include <string>

static void BM_sscanf_numbers(benchmark::State &state) {
  int i1, i2;
  float f1, f2;
  double d1, d2;
  while (state.KeepRunning()) {
    std::sscanf(test::input, "%d%f%lf%d%f%lf", &i1, &f1, &d1, &i2, &f2, &d2);
  }
}

BENCHMARK(BM_sscanf_numbers);
