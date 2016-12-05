#include "input.h"
#include <scn/detail/warning.h>
#include <benchmark/benchmark.h>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
SCN_WARNING_PUSH()
// unreferenced formal parameter
SCN_WARNING_DISABLE_MSVC(4100)
// declaration of 'attr_type' hides global declaration
SCN_WARNING_DISABLE_MSVC(4459)
#include <boost/spirit/include/qi.hpp>
SCN_WARNING_POP()

namespace qi = boost::spirit::qi;
using boost::phoenix::ref;
using qi::_1;

static void BM_boost_qi_numbers(benchmark::State &state) {
  static const std::string input{test::input::mixed};

  int i1, i2;
  float f1, f2;
  double d1, d2;

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

static void BM_boost_qi_int64(benchmark::State &state) {
  static const std::string input{test::input::int64};

  std::int64_t i;
  using int_parser = qi::int_parser<decltype(i)>;
  int_parser ip;

  auto grammar = qi::copy(ip[ref(i) = _1]);

  while (state.KeepRunning()) {
    bool ok = qi::phrase_parse(input.cbegin(), input.cend(), grammar,
                               qi::ascii::space);
    if (!ok) {
      state.SkipWithError("cannot parse");
      break;
    }
  }
}

BENCHMARK(BM_boost_qi_int64);
