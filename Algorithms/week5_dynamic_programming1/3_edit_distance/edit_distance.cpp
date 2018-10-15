#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here

    int D[str1.size() + 1][str2.size() + 1];
    D[0][0] = 0;

    for (unsigned int i = 1; i < str1.size() + 1; ++i) {
        D[i][0] = i;
    }

    for (unsigned int j = 1; j < str2.size() + 1; ++j) {
        D[0][j] = j;
    }

    for (unsigned int i = 1; i < str1.size() + 1; ++i) {
        for (unsigned int j = 1; j < str2.size() + 1; ++j) {
            if (str1.at(i - 1) == str2.at(j - 1))
                D[i][j] = std::min(std::min(D[i-1][j] + 1, D[i][j - 1] + 1) , D[i-1][j-1]);
            else
                D[i][j] = std::min(std::min(D[i-1][j] + 1, D[i][j - 1] + 1) , D[i-1][j-1] + 1);
        }
    }

  return D[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;

  return 0;
}
