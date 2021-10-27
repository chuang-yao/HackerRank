#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long candies(int n, vector<int> arr) {
  vector<long> results(n);
  results[0] = 1;
  for (size_t i = 1; i != n; ++i) {
    if (arr[i] > arr[i - 1]) {
      results[i] = results[i - 1] + 1;
    } else {
      results[i] = 1;
    }
  }
  for (size_t i = n - 1; i != 0; --i) {
    if (arr[i - 1] > arr[i]) {
      results[i - 1] = max(results[i - 1], results[i] + 1);
    }
  }
  return accumulate(results.begin(), results.end(), 0LL);
}

int main() {
  int n = 100000;
  vector<int> arr;
  arr.reserve(n);
  int k = n;
  while (k > 0) {
    arr.push_back(k);
    --k;
  }
  cout << candies(n, arr) << '\n';
}