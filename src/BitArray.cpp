#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  // 1 <= N <= 10^8
  // 0 <= S, P, Q < 2^31
  constexpr long base = 1 << 31;
  long N, S, P, Q;
  cin >> N >> S >> P >> Q;

  long prev, curr, i;
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
