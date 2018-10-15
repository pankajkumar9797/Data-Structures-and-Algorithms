#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
    if (a.empty() && b.empty() && c.empty())
        return 0;

    int D[a.size() + 1][b.size() + 1][c.size() + 1];
    D[0][0][0] = 0;

    for (unsigned int i = 0; i < a.size() + 1; ++i) {
        for (int j = 0; j < b.size() + 1; ++j) {
            for (int k = 0; k < c.size() + 1; ++k) {
                D[i][j][k] = 0;
            }
        }
    }

    for (unsigned int i = 1; i < a.size() + 1; ++i) {
        for (unsigned int j = 1; j < b.size() + 1; ++j) {
            for (int k = 1; k < c.size() + 1; ++k) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    D[i][j][k] = D[i - 1][j - 1][k - 1] + 1;
                else
                    D[i][j][k] = std::max(std::max(D[i - 1][j][k], D[i][j - 1][k]), D[i][j][k - 1]);
            }
        }

    }

  return D[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
