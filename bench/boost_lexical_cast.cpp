#include "input.h"
#include <scn/detail/warning.h>
#include <benchmark/benchmark.h>
#include <boost/lexical_cast.hpp>

static void BM_boost_lexical_cast_int64(benchmark::State &state) {
  static const std::string input{test::input::int64};

  std::int64_t i;

  while (state.KeepRunning()) {
    if (!boost::conversion::try_lexical_convert(input, i)) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_boost_lexical_cast_int64);
