#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    
    vector<int> ret;
    int curSum = 0;
    int k = 1;
    while (curSum + k + k + 1 <= n) {
        ret.push_back(k);
        curSum += k;
        k++;
    }
    if (curSum < n) {
        ret.push_back(n - curSum);
    }

    return ret;
}


int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
