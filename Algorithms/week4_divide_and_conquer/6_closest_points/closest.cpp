#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
using std::make_pair;

bool comparison(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}

double calculate_distance(std::pair <int,int> point1, std::pair <int,int> point2){
    double distance = 0.0;

    distance = sqrt((point1.first - point2.first)*(point1.first - point2.first)
                        + (point1.second - point2.second)*(point1.second - point2.second));

    return distance;
}

double compare_strip(vector<pair<int, int > > strip, int dmin){
    double min1 = dmin;
    std::sort(strip.begin(), strip.end(), comparison);

    for(auto it = strip.begin(); it != strip.end(); ++it){
        for(auto it2 = std::next(it); it2 < strip.end() && (it2->second - it->second) < min1; ++it2){
            if (calculate_distance(*it, *it2) < min1)
                min1 = calculate_distance(*it, *it2);
        }
    }
/*
    for (int i = 0; i < strip.size(); ++i) {
        pair<int, int > point = strip[i];
        for (int j = 0; j < 4; ++j) {
            if (i + j >= strip.size())
                break;
            min1 = calculate_distance(point, strip[i + j]);
        }
    }
*/
    return min1;
 }

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here

  if (x.size() == 2){
      return calculate_distance(make_pair(x[0], y[0]), make_pair(x[1], y[1]));
  }

  if (x.size() == 3){
      return min( min (calculate_distance(make_pair(x[0], y[0]), make_pair(x[1], y[1])),
                   calculate_distance(make_pair(x[0], y[0]), make_pair(x[2], y[2])) ),
                   calculate_distance(make_pair(x[1], y[1]), make_pair(x[2], y[2])) );

  }

  vector< pair<int, int> > coordinates;

  for (auto i = 0; i < x.size(); i++){
      coordinates.emplace_back(make_pair(x[i], y[i]));
  }

  std::sort(coordinates.begin(), coordinates.end());

  vector<pair<int, int> > vector_left;
  vector<pair<int, int> > vector_right;

  auto left = 0;
  auto right = static_cast<unsigned int>(x.size());
  auto mid = left + (right - left)/2;

  for (auto i = left; i < mid; i++){
    vector_left.emplace_back(coordinates[i]);
  }

  for (auto i = mid; i < right; i++){
    vector_right.emplace_back(coordinates[i]);
  }
  vector<int> temp_x_left;
  vector<int> temp_y_left;
  vector<int> temp_x_right;
  vector<int> temp_y_right;

  for (auto pair_element : vector_left){
      temp_x_left.push_back(pair_element.first);
      temp_y_left.push_back(pair_element.second);
  }

  for (auto pair_element : vector_right){
        temp_x_right.push_back(pair_element.first);
        temp_y_right.push_back(pair_element.second);
  }

  double dl = minimal_distance(temp_x_left, temp_y_left);
  double dr = minimal_distance(temp_x_right, temp_y_right);

  double dmin = min(dl, dr);

  vector<pair<int, int> > strip;
  pair<int, int> line = coordinates[mid];

  for (auto element : coordinates){
      if (abs(element.first - line.first) < dmin)
          strip.emplace_back(element);
  }

  return min(dmin, compare_strip(strip, dmin));
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
