#include "input.h"
#include <benchmark/benchmark.h>
#include <cstdlib>
#include <string>

static void BM_ato_int64(benchmark::State &state) {
  static const std::string input = test::input::int64;

  std::int64_t i;

  while (state.KeepRunning()) {
    const char *first = input.c_str();

    i = std::atoll(first);

    if (i != 44323214234) {
      state.SkipWithError("wrong parse");
      break;
    }
  }
}

BENCHMARK(BM_ato_int64);
