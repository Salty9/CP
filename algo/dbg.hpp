// header file for debugging (for competetive programming)
// got it from https://codeforces.com/blog/entry/91347
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>
// #include <stack>
#include <array>
#include <queue>
// #include <numeric>
// #include <bitset>
#include <cmath>
// #include <complex>
// #include <cstdint>
// #include <cstring>
// #include <functional>
// #include <iomanip>
#include <chrono>
#include <random>

template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = std::decay_t<decltype(*begin(std::declval<T>()))>,
          class = std::enable_if_t<!std::is_same<T, std::string>::value>>
std::ostream &operator<<(std::ostream &os, const T &c) {
  os << '[';
  for (auto it = c.begin(); it != c.end(); ++it)
    os << &", "[2 * (it == c.begin())] << *it;
  return os << ']';
}
//support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  (MACRO, ##__VA_ARGS__)
//Change output format here
#define outit(x) #x " = " << x << "; "
#define dbg(...)                                                              \
  cerr << "\e[91m" << "Line " << __LINE__ << ": " FOR_EACH_MACRO(outit, __VA_ARGS__) << "\e[39m" << "\n"