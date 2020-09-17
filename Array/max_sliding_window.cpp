#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::deque;

inline int max(const int& a, const int& b) {
    if (a < b) return b;
    return a;
}

void max_sliding_window(vector<int> const& A, int w) {
    deque<int> q;
    size_t i = 0;
    for (; i < w; i++) {
        while (!q.empty() && A[q.back()] <= A[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (; i < A.size(); ++i) {
        cout << A[q.front()] << " ";

        while (!q.empty() && q.front() <= i - w)
            q.pop_front();

        while (!q.empty() && A[q.back()] <= A[i])
            q.pop_back();

        q.push_back(i);

    }

    cout << A[q.front()] << std::endl;

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
