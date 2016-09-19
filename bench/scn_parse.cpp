#include "input.h"
#include <benchmark/benchmark.h>
#include <scn/scn.hpp>
#include <string>

static void BM_scn_numbers(benchmark::State &state) {
  int i1, i2;
  float f1, f2;
  double d1, d2;

  while (state.KeepRunning()) {
    scn::parse(test::input, "{}{}{}{}{}{}", i1, f1, d1, i2, f2, d2);
  }
}

BENCHMARK(BM_scn_numbers);
