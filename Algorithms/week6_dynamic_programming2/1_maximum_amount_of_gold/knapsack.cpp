#include <iostream>
#include <vector>

using std::vector;

long int optimal_weight_dynamic(unsigned long int W, const vector<long int> &w) {
    //write your code here
    //int current_weight = 0;

    vector<long int> gold;
    gold.push_back(0);

    for (auto it = w.begin(); it < w.end(); ++it) {
        gold.push_back(*it);
    }
    size_t gold_size = gold.size();

    vector<long int> Value(gold_size*(W + 1));

    for (size_t i = 0; i < gold.size(); ++i) {
        for (size_t j = 0; j < W + 1; ++j) {
            Value[i*(W + 1) + j] = 0;
        }
    }

    for (size_t i = 1; i < gold.size(); ++i) {
        for (size_t j = 1; j < W + 1; ++j) {
            if (j < gold[i]){
                Value[i*(W + 1) + j] = Value[(i-1)*(W + 1) + j];
            }
            else{
                Value[i*(W + 1) + j] = std::max(Value[(i - 1)*(W + 1) + j], Value[(i - 1)*(W + 1) + j - gold[i]] + gold[i]);
            }
         }
    }

    return Value[(gold_size - 1)*(W + 1) + W];
}

int main() {
  unsigned long int n, W;
  std::cin >> W >> n;
  vector<long int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
 std::cout << optimal_weight_dynamic(W, w) << '\n';

}
