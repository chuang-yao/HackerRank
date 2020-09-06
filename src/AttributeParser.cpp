#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  cin.ignore();

  vector<string> source;
  vector<string> query;

  for (int i = 0; i != N; ++i) {
    string s;
    getline(cin, s);
    source.push_back(s);
  }
  for (int i = 0; i != Q; ++i) {
    string s;
    getline(cin, s);
    query.push_back(s);
  }

  unordered_map<string, unordered_map<string, string>> A;
  vector<string> tag_list;

  for (const auto &str : source) {
    stringstream ss(str);
    string word;
    vector<string> line;
    while (ss >> word) {
      line.push_back(word);
    }
    if (line.size() == 1) {
      line[0].erase(line[0].begin());
      line[0].erase(line[0].end() - 1);
    } else {
      line[0].erase(line[0].begin());
      line[line.size() - 1].erase(line[line.size() - 1].end() - 1);
    }
    string tag = line[0];
    tag_list.push_back(tag);
    if (tag[0] != '/') {
      for (auto itr = line.begin(); itr != line.end(); ++itr) {
        if (*itr == "=") {
          string key = *(itr - 1);
          string raw_value = *(itr + 1);
          string value = raw_value.substr(1, raw_value.size() - 2);
          A[tag][key] = value;
        }
      }
    }
  }

  for (const auto &q : query) {
    auto tilde_pos = q.find('~');
    string key = q.substr(tilde_pos + 1);

    vector<string> path;
    string tag;
    stringstream ss(q.substr(0, tilde_pos));
    while (getline(ss, tag, '.')) {
      path.push_back(tag);
    }
    tag = path.back();

    stack<string> stack;
    stack.push(tag);
    auto itr = find(tag_list.begin(), tag_list.end(), tag);

    --itr;
    for (; itr >= tag_list.begin(); --itr) {
      if (*itr == stack.top().substr(1)) {
        stack.pop();
      } else {
        stack.push(*itr);
      }
    }

    vector<string> generated_path;
    for (auto tmp = stack; !tmp.empty(); tmp.pop()) {
      generated_path.push_back(tmp.top());
    }

    if (generated_path == path &&
        (find(tag_list.begin(), tag_list.end(), tag) != tag_list.end()) &&
        (A[tag].find(key) != A[tag].end())) {
      cout << A[tag][key] << '\n';
    } else {
      cout << "Not Found!\n";
    }
  }

  return 0;
}
