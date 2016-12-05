#include "input.h"
#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>

static void BM_strto_numbers(benchmark::State &state) {
  static const std::string input = test::input::mixed;

  int i1, i2;
  float f1, f2;
  double d1, d2;

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

    if (first != (input.c_str() + input.size())) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_strto_numbers);

static void BM_strto_int64(benchmark::State &state) {
  static const std::string input = test::input::int64;

  std::int64_t i;

  while (state.KeepRunning()) {
    const char *first = input.c_str();
    char *last;

    i = std::strtoll(first, &last, 10);
    first = last;

    if (first != (input.c_str() + input.size())) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_strto_int64);
