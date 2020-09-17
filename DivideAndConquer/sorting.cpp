#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int>& a, int l, int r) {
    int x = a[l];
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] <= x) {
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}

// Dijkstra Dutch national flag partition algorithm
void partition3(vector<int>& a, int l, int r, int& m1, int& m2) {

    if (l > r) {
        m1 = l;
        m2 = r;
    }

    int pivot = a[l];

    int i = l, j = l, k = r + 1;
    while (j < k) {
        if (a[j] < pivot) {
            swap(a[i], a[j]);
            i++, j++;
        }
        else if (a[j] > pivot) {
            k--;
            swap(a[j], a[k]);
        }
        else
            j++;
    }

    m1 = i;
    m2 = j-1;

}

void randomized_quick_sort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    int m1, m2;
    partition3(a, l, r, m1, m2);

    randomized_quick_sort(a, l, m1 - 1);
    randomized_quick_sort(a, m2 + 1, r);
}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
}
