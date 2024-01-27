#include <cassert>
#include <string>
#include <iostream>
#include <set>

struct NoCopy
{
  int a_;
  NoCopy(int a)
  {
    a_ = a;
  }
  NoCopy(const NoCopy &) = delete;
  bool operator<(const NoCopy &other) const
  {
    return a_ < other.a_;
  }

  bool operator==(const NoCopy &other)
  {
    return (a_ == other.a_);
    return ( (! (*this < other)) && (! ( other < *this)));
  }
};

template <typename T>
T& min(T &a, T &b)
{
  if ((a) < (b))

    return (a);
  else
    return (b);
}

template <typename T>
T& max(T &a, T  &b)
{
  if (!((a) < (b)))
    return (a);
  else
    return (b);
}

int main()
{
  NoCopy a(3), b(5 + 5);
  assert(min(a, b) == a);
}