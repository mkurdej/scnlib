#include "input.h"
#include <benchmark/benchmark.h>
#include <string>

static void BM_sto_int64(benchmark::State &state) {
  static const std::string input = test::input::int64;

  std::int64_t i;

  while (state.KeepRunning()) {
    i = std::stoll(input);

    if (i != 44323214234) {
      state.SkipWithError("wrong parse");
      break;
    }
  }
}

BENCHMARK(BM_sto_int64);
