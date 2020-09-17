#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

enum kind { left, point, right};

struct elem{
    int x;
    kind t;
    int ind; // index in original array
    elem(int val, kind typ, int i = 0) : x(val), t(typ), ind(i) {}
};

bool comparator(const elem& l, const elem& r)
{
    if (l.x < r.x)
        return true;
    if (l.x == r.x) {
        return l.t < r.t;
    }
    return false;
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

vector<int> fast_count_segments(vector<elem> helper, int numOfPoints) {
      
    sort(helper.begin(), helper.end(), comparator);

    vector<int> ret(numOfPoints);
    int numLefts = 0, numRights = 0;
    for (auto it = helper.begin(); it != helper.end(); ++it) {
        if ((*it).t == point) {
            ret[(*it).ind] = (max(0, numLefts - numRights));
            continue;
        }
        if ((*it).t == left) {
            numLefts++;
            continue;
        }
        if ((*it).t == right) {
            numRights++;
        }
    }

    return ret;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < starts.size(); j++) {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<elem> arr;
    for (int i = 0; i < n; i++) {
        int start, end;
        std::cin >> start >> end;
        arr.push_back(elem(start, left));
        arr.push_back(elem(end, right));
    }
    for (int i = 0; i < m; i++) {
        int p;
        std::cin >> p;
        arr.push_back(elem(p, point, i));
    }
    //use fast_count_segments
    vector<int> cnt = fast_count_segments(arr, m);
    for (size_t i = 0; i < cnt.size(); i++) {
        std::cout << cnt[i] << ' ';
    }
}
