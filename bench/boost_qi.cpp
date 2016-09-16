#include "input.h"
#include <benchmark/benchmark.h>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/qi.hpp>

static const std::string input{test::input};

namespace qi = boost::spirit::qi;

static void BM_boost_qi_numbers(benchmark::State &state) {
  int i1, i2;
  float f1, f2;
  double d1, d2;

  using boost::phoenix::ref;
  using qi::_1;

  auto grammar =
      qi::copy(qi::int_[ref(i1) = _1] >> qi::float_[ref(f1) = _1] >>
               qi::double_[ref(d1) = _1] >> qi::int_[ref(i2) = _1] >>
               qi::float_[ref(f2) = _1] >> qi::double_[ref(d2) = _1]);

  while (state.KeepRunning()) {
    bool ok = qi::phrase_parse(input.cbegin(), input.cend(), grammar,
                               qi::ascii::space);
    if (!ok) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_boost_qi_numbers);
