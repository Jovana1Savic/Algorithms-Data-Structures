#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int>& b, size_t left, size_t mid, size_t right) {

    long long inversions = 0;
    vector<int> res;
    size_t i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (b[i] <= b[j]) {
            res.push_back(b[i++]);
        }
        else {
            res.push_back(b[j++]);
            inversions+= ((long)mid - (long)i + 1);
        }
    }

    while (i <= mid) {
        res.push_back(b[i++]);
    }

    while (j <= right) {
        res.push_back(b[j++]);
    }

    for (i = 0, j = left; j <= right; i++, j++) {
        b[j] = res[i];
    }

    return inversions;
}

long long mergeSort(vector<int>& arr, size_t left, size_t right) {

    if (left >= right)
        return 0;

    long long inversions = 0;
    size_t mid = left + (right - left) / 2;
    inversions +=  mergeSort(arr, left, mid);
    inversions +=  mergeSort(arr, mid + 1, right);
    inversions += merge(arr, left, mid, right);
    return inversions;
}
long long get_number_of_inversions(vector<int>& a) {

    long long number_of_inversions;
    vector<int> b = a;

    number_of_inversions = mergeSort(b, 0, b.size() - 1);

    return number_of_inversions;

}

int main() {
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << get_number_of_inversions(a) << '\n';
}
