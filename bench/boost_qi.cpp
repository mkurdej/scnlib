#include <benchmark/benchmark.h>
#include <boost/spirit/include/qi.hpp>

static const std::string input = "12 132.43 234.5 -43 -34e-3 -4.53e3";

static void BM_boost_qi_numbers(benchmark::State &state) {
  // grammar

  int i1, i2;
  float f1, f2;
  double d1, d2;
  while (state.KeepRunning()) {
    // parse_phrase
  }
}

BENCHMARK(BM_boost_qi_numbers);
