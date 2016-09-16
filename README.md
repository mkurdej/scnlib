= libscn =

Like libfmt, but for parsing. I.e. a type-safe alternative for scanf.

Goals:
* Faster than scanf
* Limit memory allocations
* Use compile-time information where possible
* Benchmark against scanf and Boost.Spirit.Karma.