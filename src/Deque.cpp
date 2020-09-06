#include <deque>
#include <iostream>

using namespace std;

void printKMax(int arr[], int n, int k) {
  deque<int> buffer;
  for (int i = 0; i != k; ++i) {
    while (!buffer.empty() && arr[i] >= arr[buffer.back()]) {
      buffer.pop_back();
    }
    buffer.push_back(i);
  }
  for (int i = k; i != n; ++i) {
    cout << arr[buffer.front()] << ' ';
    while (!buffer.empty() && buffer.front() <= i - k) {
      buffer.pop_front();
    }
    while (!buffer.empty() && arr[i] >= arr[buffer.back()]) {
      buffer.pop_back();
    }
    buffer.push_back(i);
  }
  cout << arr[buffer.front()] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i != n; ++i) {
      cin >> arr[i];
    }
    printKMax(arr, n, k);
  }
  return 0;
}
