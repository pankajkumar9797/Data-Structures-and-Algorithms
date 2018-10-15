#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here

  if (a.empty() && b.empty())
    return 0;

  int D[a.size() + 1][b.size() + 1];
  D[0][0] = 0;

  for (unsigned int i = 0; i < a.size() + 1; ++i) {
    for (int j = 0; j < b.size() + 1; ++j) {
      D[i][j] = 0;
    }
  }

  for (unsigned int i = 1; i < a.size() + 1; ++i) {
    for (unsigned int j = 1; j < b.size() + 1; ++j) {
      if (a[i - 1] == b[j - 1])
        D[i][j] = D[i - 1][j - 1] + 1;
      else
        D[i][j] = std::max(D[i - 1][j], D[i][j - 1]);
    }

  }

//  return std::min(std::min(a.size(), b.size()), c.size());
  return D[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
