#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<int, int> segment;
bool comparator(const segment& l, const segment& r)
{
    if (l.first < r.first)
        return true;
    if (l.first == r.first)
        return l.second < r.second;
    return false;
}

bool empty(const segment& s) {
    return s.first == -1 && s.second == -1;
}

segment intersection(const segment& a, const segment& b) {

    segment ret(-1, -1);
    if (b.first > a.second)
        return ret;
    ret.first = b.first;
    ret.second = min(a.second, b.second);
    return ret;
}
vector<int> optimal_points(vector<segment>& segments) {
    
    if (segments.empty())
        return vector<int>();

    //write your code here
    sort(segments.begin(), segments.end(), comparator);
    vector<int> points;

    int i = 1;
    segment lastCovered = segments[0];
    while (i < segments.size()) {
        segment newLastCovered = lastCovered;
        while (i < segments.size() && (!empty(intersection(lastCovered, segments[i]))) &&
            (!empty(intersection(newLastCovered, segments[i]))) ) {
           newLastCovered = intersection(newLastCovered, segments[i]);
           i++;
        }
        points.push_back(newLastCovered.second);

        if (i == segments.size())
            return points;
        lastCovered = segments[i];
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].first >> segments[i].second;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
