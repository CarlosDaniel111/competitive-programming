#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<string> split(string str, char pattern) {
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2025/Dia6/input.txt");

  string line;
  vector<string> parsed_input;
  size_t longest_size = 0;

  while (getline(file, line)) {
    if (line[0] == '+' || line[0] == '-' || line[0] == '*' || line[0] == '/')
      break;
    for (auto& c : line) {
      if (c == ' ') c = '.';
    }
    longest_size = max(longest_size, line.size());
    parsed_input.push_back(line);
  }

  const string signs = line;
  for (auto& line : parsed_input) {
    while (line.size() < longest_size) {
      line += '.';
    }
  }

  size_t start = 0;
  size_t end = end = signs.find_first_not_of(' ', start + 1);
  vector<size_t> start_indices;
  do {
    auto sign = signs[start];
    end = signs.find_first_not_of(' ', start + 1);
    start_indices.push_back(start);
    start = end;
  } while (end != string::npos);
  start_indices.push_back(longest_size + 1);
  vector<string> numbers_str(longest_size);
  for (auto& row : parsed_input) {
    for (int i = 0; i < longest_size; i++) {
      numbers_str[i] += row[i];
    }
  }
  auto remove_char = [](string& s) {
    s.erase(remove(s.begin(), s.end(), '.'), s.end());
    return s;
  };

  size_t total = 0;
  for (int i = 0; i < start_indices.size() - 1; i++) {
    auto start = start_indices[i];
    auto end = start_indices[i + 1] - 1;
    auto sign = signs[start];
    size_t ans = 0;
    if (sign == '+') {
      ans = accumulate(next(begin(numbers_str), start),
                       next(begin(numbers_str), end), size_t(0),
                       [&](size_t sum, string ele) {
                         return stoull(remove_char(ele)) + sum;
                       });
    } else if (sign == '*') {
      ans = accumulate(next(begin(numbers_str), start),
                       next(begin(numbers_str), end), size_t(1),
                       [&](size_t prod, string ele) {
                         return stoull(remove_char(ele)) * prod;
                       });
    }
    total += ans;
  }
  cout << total << '\n';

  return 0;
}