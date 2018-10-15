#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cfloat>

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

double compare_strip(vector<pair<int, int > > strip, double dmin){
    double min1 = dmin;
    std::sort(strip.begin(), strip.end(), comparison);

    for(auto it = strip.begin(); it != strip.end(); ++it){
        for(auto it2 = std::next(it); it2 < strip.end() && (it2->second - it->second) < min1; ++it2){
            if (calculate_distance(*it, *it2) < min1)
                min1 = calculate_distance(*it, *it2);
        }
    }
    return min1;
 }

double bruteForce(vector<pair<int, int > > coordinates){

    auto min_value = DBL_MAX;

    for(auto it1 = coordinates.begin(); it1 != coordinates.end(); ++it1){
        for (auto it2 = std::next(it1); it2 != coordinates.end(); ++it2){
            if (calculate_distance(*it1, *it2) < min_value)
                min_value = calculate_distance(*it1, *it2);
        }
    }
    return min_value;
}

double minimal_distance(vector<pair<int, int > > coordinates) {
    //write your code here


    if (coordinates.size() < 5){
        return bruteForce(coordinates);
    }

    vector<pair<int, int> > vector_left;
    vector<pair<int, int> > vector_right;

    auto left = 0;
    auto right = static_cast<unsigned int>(coordinates.size());
    auto mid = static_cast<unsigned int>((left + right)/2);

    for (auto i = left; i < mid; i++){
        vector_left.emplace_back(coordinates[i]);
    }

    for (auto i = mid; i < right; i++){
        vector_right.emplace_back(coordinates[i]);
    }

    double dl = minimal_distance(vector_left);
    double dr = minimal_distance(vector_right);

    double dmin = min(dl, dr);

    vector<pair<int, int> > strip;
    pair<int, int> line = coordinates[mid + 1];

    for (auto element : coordinates){
        if (abs(element.first - line.first) < dmin)
            strip.emplace_back(element);
    }

    return min(dmin, compare_strip(strip, dmin));
}

double closestPoints(vector<int> x, vector<int> y){
    vector< pair<int, int> > coordinates;

    for (auto i = 0; i < x.size(); i++){
        coordinates.emplace_back(make_pair(x[i], y[i]));
    }

    std::sort(coordinates.begin(), coordinates.end());

    return minimal_distance(coordinates);
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
  std::cout << std::setprecision(9) << closestPoints(x, y) << "\n";
}
