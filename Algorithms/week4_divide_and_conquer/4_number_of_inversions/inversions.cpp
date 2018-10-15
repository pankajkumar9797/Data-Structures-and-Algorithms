#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, size_t left, size_t mid, size_t right, vector<int> &b){
  long long number_of_inversions = 0;
  unsigned int start = static_cast< unsigned int>(left);
  unsigned int end = static_cast<unsigned int>(mid) + 1;
  unsigned int index = static_cast<unsigned int>(left);

  while (start <= mid && end <= right){
    if (a[start] <= a[end]){
      b[index++] = a[start++];
    } else{
      number_of_inversions += (mid - start + 1);
      b[index++] = a[end++];
    }
  }
  while (start <= mid){
    b[index++] = a[start++];
  }
  while (end <= right){
    b[index++] = a[end++];
  }

  for (index = static_cast<unsigned int>(left); index <= static_cast<unsigned int>(right); index++){
    a[index] = b[index];
  }
  return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = (right + left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
  //write your code here
  number_of_inversions += merge(a, left, ave, right, b);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
