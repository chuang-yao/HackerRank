#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  // 1 <= N <= 10^8
  // 0 <= S, P, Q < 2^31
  constexpr unsigned long base = 1UL << 31;
  unsigned long N, S, P, Q;
  cin >> N >> S >> P >> Q;

  unsigned long prev, curr, i;
  curr = prev = S % base;
  for (i = 1; i != N; ++i) {
    curr = (prev * P + Q) % base;
    if (curr == prev || curr == S) {
      break;
    }
    prev = curr;
  }
  cout << i << '\n';
  return 0;
}
