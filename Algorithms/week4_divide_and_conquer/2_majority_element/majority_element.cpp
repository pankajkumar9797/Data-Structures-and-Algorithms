#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

/*
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  std::sort(a.begin(), a.end());
  int last_index = left + (right - left)/2;//(right - left)%2 == 0 ? ((right - left)/2 + 1): (right - left)/2;

  for (int i = left; i < last_index; ++i) {
    if (a[i] == a[i + last_index]) return 1;
  }
  return -1;
}
*/

int get_majority_element(vector<int> &a, int left, int right) {
  std::unordered_map<int , int> map;
  int n = right - left;

  for (int i = left; i < right; i++) {
    map[a[i]]++;
  }

  for (auto pair : map) {
    if (pair.second > n/2)
      return 1;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
