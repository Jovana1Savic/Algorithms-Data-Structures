#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<double, int> loot;
bool comparator(const loot& l, const loot& r)
{
    return l.first > r.first;
}


double get_optimal_value(int capacity, vector<loot> loots) {
    double value = 0.0;
    sort(loots.begin(), loots.end(), comparator);
    // write your code here
    for (auto it = loots.begin(); it != loots.end() && capacity > 0; ++it) {
        int weight = min(capacity, (*it).second);
        capacity -= weight;
        value += (*it).first * weight;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<loot> loots;
    for (int i = 0; i < n; i++) {
        int val, weight;
        cin >> val >> weight;
        loot l;
        l.first = (val * 1.00) / weight;
        l.second = weight;
        loots.push_back(l);
    }

    double optimal_value = get_optimal_value(capacity, loots);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
