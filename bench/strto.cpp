#include "input.h"
#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>

static void BM_strto_numbers(benchmark::State &state) {
  int i1, i2;
  float f1, f2;
  double d1, d2;

  const std::string input = test::input;

  while (state.KeepRunning()) {
    const char *first = input.c_str();
    char *last;

    i1 = std::strtol(first, &last, 10);
    first = last;

    f1 = std::strtof(first, &last);
    first = last;

    d1 = std::strtod(first, &last);
    first = last;

    i2 = std::strtol(first, &last, 10);
    first = last;

    f2 = std::strtof(first, &last);
    first = last;

    d2 = std::strtod(first, &last);
    first = last;
  }
}

BENCHMARK(BM_strto_numbers);
