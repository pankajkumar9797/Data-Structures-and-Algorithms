/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
    vector<int> sequence;

    vector<int> arr(n + 1, 0);

    for (int i = 1; i < arr.size(); i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(1 + arr[i / 2], arr[i]);
        if (i % 3 == 0) arr[i] = min(1 + arr[i / 3], arr[i]);

    }

    for (int i = n; i > 1; ) {
        sequence.push_back(i);
        if (arr[i - 1] == arr[i] - 1)
            i = i - 1;
        else if (i % 2 == 0 && (arr[i / 2] == arr[i] - 1))
            i = i / 2;
        else if (i % 3 == 0 && (arr[i / 3] == arr[i] - 1))
            i = i / 3;
    }
    sequence.push_back(1);

    std::reverse(sequence.begin(), sequence.end());

    return sequence;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }

    return 0;
}
