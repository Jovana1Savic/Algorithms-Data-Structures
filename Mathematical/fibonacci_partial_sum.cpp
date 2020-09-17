#include <iostream>
#include <vector>
using std::vector;

const int period = 60;
int seq[period];

void initializeSeq() {
    seq[0] = 0;
    seq[1] = 1;
    for (int i = 2; i < period; i++) {
        seq[i] = (seq[i - 1] + seq[i - 2]) % 10;
    }
}

int getFibonacciSum(long long n) {

    initializeSeq();
    int s = seq[(n + 2) % period] - 1;
    if (s < 0)
        s += 10;
    return s;
}

long long getFibonacciPartialSum(long long from, long long to) {
    
    int s = getFibonacciSum(to) - getFibonacciSum(from - 1);
    if (s < 0)
        s += 10;
    return s;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << getFibonacciPartialSum(from, to) << '\n';
}
