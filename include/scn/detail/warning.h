#pragma once

#include <boost/predef/compiler.h>

#ifndef SCN_PRAGMA_IMPL
#if BOOST_COMP_MSVC
#define SCN_PRAGMA_IMPL(prgm) __pragma(prgm)
#elif BOOST_COMP_GNUC || BOOST_COMP_CLANG
#define SCN_PRAGMA_IMPL(prgm) _Pragma(#prgm)
#else
#define SCN_PRAGMA_IMPL(prgm)
#error "Unknown compiler!"
#endif
#endif

#ifndef SCN_WARNING_PUSH
#if BOOST_COMP_MSVC
#define SCN_WARNING_PUSH() SCN_PRAGMA_IMPL(warning(push))
#elif BOOST_COMP_GNUC
#define SCN_WARNING_PUSH() SCN_PRAGMA_IMPL(GCC diagnostic push)
#elif BOOST_COMP_CLANG
#define SCN_WARNING_PUSH() SCN_PRAGMA_IMPL(clang diagnostic push)
#else
#define SCN_WARNING_PUSH()
#endif
#endif

#ifndef SCN_WARNING_DISABLE_MSVC
#if BOOST_COMP_MSVC
#define SCN_WARNING_DISABLE_MSVC(wrngs) SCN_PRAGMA_IMPL(warning(disable: wrngs))
#else
#define SCN_WARNING_DISABLE_MSVC(wrngs)
#endif
#endif

#ifndef SCN_WARNING_DISABLE_GNUC
#if BOOST_COMP_GNUC
#define SCN_WARNING_DISABLE_GNUC(wrngs) SCN_PRAGMA_IMPL(GCC diagnostic ignored wrngs)
#else
#define SCN_WARNING_DISABLE_GNUC(wrngs)
#endif
#endif

#ifndef SCN_WARNING_DISABLE_CLANG
#if BOOST_COMP_CLANG
#define SCN_WARNING_DISABLE_CLANG(wrngs) SCN_PRAGMA_IMPL(clang diagnostic ignored wrngs)
#else
#define SCN_WARNING_DISABLE_CLANG(wrngs)
#endif
#endif

#ifndef SCN_WARNING_POP
#if BOOST_COMP_MSVC
#define SCN_WARNING_POP() SCN_PRAGMA_IMPL(warning(pop))
#elif BOOST_COMP_GNUC
#define SCN_WARNING_POP() SCN_PRAGMA_IMPL(GCC diagnostic pop)
#elif BOOST_COMP_CLANG
#define SCN_WARNING_POP() SCN_PRAGMA_IMPL(clang diagnostic pop)
#else
#define SCN_WARNING_POP()
#endif
#endif

#ifndef SCN_WARNING_SUPPRESS_MSVC
#if BOOST_COMP_MSVC
#define SCN_WARNING_SUPPRESS_MSVC(wrngs) SCN_PRAGMA_IMPL(warning(suppress: wrngs))
#else
#define SCN_WARNING_SUPPRESS_MSVC(wrngs)
#endif
#endif
