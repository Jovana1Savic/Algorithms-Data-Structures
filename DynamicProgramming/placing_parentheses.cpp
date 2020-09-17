#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

long long m[14][14];
long long M[14][14];

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    }
    else if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        assert(0);
    }
}

long long min(long long a, long long b) {
    if (a < b) return a;
    return b;
}

long long min(long long a, long long b, long long c, long long d, long long e) {
    
    return min(min(min(a, b), min(c, d)), e);
}

long long max(long long a, long long b) {
    if (a > b) return a;
    return b;
}

long long max(long long a, long long b, long long c, long long d, long long e) {

    return max(max(max(a, b), max(c, d)), e);
}

long long min(int i, int j, string num, string op) {
    long long minimum = LLONG_MAX;
    for (int k = i; k < j; k++) {
        long long a = eval(M[i][k], M[k + 1][j], op[k]);
        long long b = eval(M[i][k], m[k + 1][j], op[k]);
        long long c = eval(m[i][k], M[k + 1][j], op[k]);
        long long d = eval(m[i][k], m[k + 1][j], op[k]);

        minimum = min(minimum, a, b, c, d);
    }

    return minimum;
}

long long max(int i, int j, string num, string op) {
    long long maximum = LLONG_MIN;
    for (int k = i; k < j; k++) {
        long long a = eval(M[i][k], M[k + 1][j], op[k]);
        long long b = eval(M[i][k], m[k + 1][j], op[k]);
        long long c = eval(m[i][k], M[k + 1][j], op[k]);
        long long d = eval(m[i][k], m[k + 1][j], op[k]);

        maximum = max(maximum, a, b, c, d);
    }

    return maximum;
}

long long get_maximum_value(const string& exp) {
    
    string nums = ""; string op = "";
    for (int i = 0; i < exp.size(); i++) {
        if (i % 2 == 0) {
            nums.push_back(exp[i]);
        }
        else {
            op.push_back(exp[i]);
        }
    }

    int n = nums.size();

    for (int i = 0; i < n; i++) {
        m[i][i] = M[i][i] = (long long)(nums[i] - '0');
    }

    for (int s = 1; s <= n - 1; s++) {
        for (int i = 0; i < n - s; i++) {
            int j = i + s;
            m[i][j] = min(i, j, nums, op);
            M[i][j] = max(i, j, nums, op);
        }
    }

    return M[0][n - 1];
}

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
