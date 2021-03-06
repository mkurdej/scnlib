#include "input.h"
#include <benchmark/benchmark.h>
#include <sstream>
#include <string>

static void BM_stringstream_numbers(benchmark::State &state) {
  int i1, i2;
  float f1, f2;
  double d1, d2;

  std::istringstream is(test::input);

  while (state.KeepRunning()) {
    is.seekg(0); // rewind
    is >> i1 >> f1 >> d1 >> i2 >> f2 >> d2;
    if (is.bad()) {
      state.SkipWithError("cannot parse");
      break;
    }

    if (!is.eof()) {
      state.SkipWithError("should reach end-of-file");
      break;
    }
  }
}

BENCHMARK(BM_stringstream_numbers);
