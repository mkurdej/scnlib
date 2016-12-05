#define __STDC_FORMAT_MACROS
#include "input.h"
#include <benchmark/benchmark.h>
#include <cinttypes>
#include <cstdio>
#include <string>

static void BM_sscanf_numbers(benchmark::State &state) {
  int i1, i2;
  float f1, f2;
  double d1, d2;

  while (state.KeepRunning()) {
    int successes = std::sscanf(test::input::mixed, "%d%f%lf%d%f%lf", &i1, &f1,
                                &d1, &i2, &f2, &d2);
    if (successes != 6) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_sscanf_numbers);

static void BM_sscanf_int64(benchmark::State &state) {
  std::int64_t i;

  while (state.KeepRunning()) {
    int successes = std::sscanf(test::input::int64, "%" SCNd64, &i);
    if (successes != 1) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_sscanf_int64);
