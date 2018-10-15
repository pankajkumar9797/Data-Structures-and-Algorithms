#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here

  int sum_of_elems = 0;
  for (auto& n : A)
    sum_of_elems += n;

  int W = sum_of_elems/3;

  auto result = std::max_element(A.begin(), A.end());
  if (sum_of_elems % 3 != 0 || A.size() < 3)//*result > W ||
    return 0;

//  std::sort(A.begin(), A.end());

  vector<int> D((A.size() + 1)*(W + 1));

  for (int i = 0; i < W + 1; ++i) {
    for (int j = 0; j < A.size() + 1; ++j) {
      D[i*A.size() + j] = 0;
    }  
  }

  for (size_t i = 1; i < W + 1; ++i) {
      std::cout << std::endl;
    for (size_t j = 1; j < A.size() + 1; ++j) {
      int ii = static_cast<int>(i) - A[j - 1];
        std::cout << D[ii*(A.size() + 1) + j - 1] <<" ";
      if ((A[j - 1] == static_cast<int>(i)) || (ii > 0 && D[ii*(A.size() + 1) + j - 1])){
        D[i*(A.size() + 1) + j] = D[i*(A.size() + 1) + j - 1] == 0 ? 1 : 2 ;
      }
      else
        D[i*(A.size() + 1) + j] = D[i*(A.size() + 1) + j - 1];

    }
  }

    for (int i = 0; i < W + 1; ++i) {
      std::cout << std::endl;
        for (int j = 0; j < A.size() + 1; ++j) {
            std::cout << D[i*(A.size() + 1) + j] <<" ";
        }
    }

  return D[(A.size() + 1)*(W + 1) - 2] == 2 ? 1 : 0;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
//  partition3(A);
}
