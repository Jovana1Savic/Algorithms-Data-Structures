#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    
    int pos = 0;
    int lastRefil = 0;
    int travelled = 0;
    int refils = 0;
    while (travelled + tank < dist) {
        int nextRefil = lastRefil;
        while ((travelled < dist) && (pos < stops.size()) && (stops[pos] - lastRefil <= tank)) {
            travelled = stops[pos];
            nextRefil = stops[pos];
            pos++;
        }
        if (travelled == dist) {
            return refils;
        }
        if (lastRefil == nextRefil) {
            return -1;
        }
        refils++;
        lastRefil = nextRefil;
    }
    return refils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
