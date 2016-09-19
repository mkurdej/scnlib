#pragma once

#include <scn/detail/warning.h>
#include <string>

namespace scn {
namespace detail {

template <typename...>
struct conjunction : std::true_type {};

template <typename B1>
struct conjunction<B1> : B1 {};

template <typename B1, typename... Bn>
struct conjunction<B1, Bn...>
    : std::conditional_t<B1::value != false, conjunction<Bn...>, B1> {};

template <typename... B>
constexpr bool conjunction_v = conjunction<B...>::value;

template <typename... T>
using are_lvalue_references = conjunction<std::is_lvalue_reference<T>...>;

template <typename... B>
constexpr bool are_lvalue_references_v = are_lvalue_references<B...>::value;

} // namespace detail

SCN_WARNING_PUSH()
SCN_WARNING_DISABLE_MSVC(4100)

template <typename... Args>
static void parse(const std::string &s, const char *parse_str, Args &... args) {
  (void)s;
  (void)parse_str;
  static_assert(detail::are_lvalue_references_v<decltype(args)...>,
                "arguments should be modifiable (l-value references)");
}

SCN_WARNING_POP()

} // namespace scn