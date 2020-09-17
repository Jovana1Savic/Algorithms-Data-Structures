#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;


#define DBL_MAX 1.7976931348623157e308

struct point {
    long long x;
    long long y;
    point(long long x, long long y) {
        this->x = x;
        this->y = y;
    }
};

bool comparatorX(const point& l, const point& r) {
    return l.x < r.x;
}

bool comparatorY(const point& l, const point& r) {
    return l.y < r.y;
}

double distance(const point& p1, const point& p2) {
    
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

int getLeftInd(const vector<point>& points, int left, int right, long long key) {

    int ret = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (points[mid].x == key) {
            ret = mid;
            right = mid - 1;
        }
        else if (points[mid].x > key) {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    if (ret != -1)
        return ret;

    return left;
}

int getRightInd(const vector<point>& points, int left, int right, long long key) {
    
    int ret = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (points[mid].x == key) {
            ret = mid;
            left = mid + 1;
        }
        else if (points[mid].x > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (ret != -1)
        return ret;

    return right;
}

double minimalDistanceUtil(vector<point>& points, int left, int right) {

    if (left >= right)
        return DBL_MAX;
    
    if (left + 1 == right) {
        return distance(points[left], points[right]);
    }
    

    int mid = left + ((right - left) >> 1);
    long long x_mid = points[mid].x;

    double dLeft = minimalDistanceUtil(points, left, mid);
    double dRight = minimalDistanceUtil(points, mid + 1, right);

    double d = min(dLeft, dRight);
    int limit = (int)floor(d);

    int indLeft = getLeftInd(points, left, mid, x_mid - limit);
    int indRight = getRightInd(points, mid + 1, right, x_mid + limit);

    if (indLeft >= indRight) {
        // No merge, there's nothing in range [x_mid - limit, x_mid + limit]
        return d;
    }

    vector<point> tmp;
    for (int i = indLeft; i <= indRight; i++) {
        tmp.push_back(points[i]);
    }
    std::sort(tmp.begin(), tmp.end(), comparatorY);

    // Try to find something.
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = i + 1; j < tmp.size() && j < i + 8; j++) { // this one does not repeat more than 8 times.
            double d_tmp = distance(tmp[i], tmp[j]);
            if (d_tmp < d)
                d = d_tmp;
        }
    }

    return d;
}
double minimalDistance(vector<point>& points) {
    
    std::sort(points.begin(), points.end(), comparatorX);
    return minimalDistanceUtil(points, 0, points.size() - 1);
}

int main() {
    size_t n;
    std::cin >> n;
    vector<point> points;
    for (size_t i = 0; i < n; i++) {
        long long x, y;
        std::cin >> x >> y;
        points.push_back(point(x, y));
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimalDistance(points) << "\n";
}
