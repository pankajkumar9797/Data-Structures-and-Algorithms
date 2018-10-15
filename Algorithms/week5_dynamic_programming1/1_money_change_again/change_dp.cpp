/* This program is a tutorial for learning DYNAMIC PROGRAMMING
 * It calculates the minimum number of coins required to change a
 * amount. It also prints out the coin denominations
 *
 * Author: Pankaj Kumar MSc.
 */

#include <iostream>
#include <vector>
#include <climits>

using std::vector;

/* This function prints out the minimum number of coins needed
 * and the required coins.
 */
void printCoins(int minCoins, vector<int> coinsUsed){
    auto coin = coinsUsed.size() - 1;
    std::cout <<"Number of coins used : " << minCoins << std::endl;
    while(coin != 0 ){
        int thisCoin = coinsUsed[coin];
        std::cout << thisCoin <<" ";
        coin = coin - thisCoin;
    }

    std::cout << std::endl;
}
/* minCoins(m + 1, INT_MAX) Array of size amount + 1(initial value = INF) This
 * array stores the minimum number of coins need to make a change.. starting from
 * zero till the amount.
 *
 * coinsUsed(m + 1, -1) stores the indices of the coins of array coinValueList such that sum of coins
 * is equal to the amount.
 *
 * First loop passes through the coinValueList array and second loop is a bottom up till the amount
 * If condition loop checks that the amount value should be greater than the value in a coins list.
 * Second condition checks if sub-problem related to this has a previous solution.
 *
 */
void get_change(int m, vector<int> coinValueList) {
  //write your code here
  vector<int> minCoins(m + 1, INT_MAX); //
  vector<int> coinsUsed(m + 1, -1);
  minCoins[0] = 0;

  for (int i = 0; i < coinValueList.size(); ++i) {
    for (int j = 0; j < m + 1; ++j) {
      if ( j >= coinValueList[i] && 1 + minCoins[j - coinValueList[i]] < minCoins[j]) {
            minCoins[j] = std::min(minCoins[j], 1 + minCoins[j - coinValueList[i]]); // Minimum value from previous value in an array minCoins and current calculated.
            coinsUsed[j] = coinValueList[i];
      }
    }
  }

  printCoins(minCoins[m], coinsUsed);
}

int main() {
  int amount;
  vector<int> coinValueList{1, 3, 4};

  std::cin >> amount;
  get_change(amount, coinValueList);
}
