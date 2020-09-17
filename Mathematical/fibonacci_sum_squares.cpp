#include <iostream>
#include <vector>
using std::vector;

// Sum of squares of Fibonacci numbers is S(n) = F(n)*F(n-1)
const int period = 60;
int seq[period];

void initializeSeq() {
    seq[0] = 0;
    seq[1] = 1;
    for (int i = 2; i < period; i++) {
        seq[i] = (seq[i - 1] + seq[i - 2]) % 10;
    }
}

int getFibonacci(long long n) {

    initializeSeq();
    int s = seq[(n) % period] - 1;
    if (s < 0)
        s += 10;
    return s;
}

long long getFibonacciSumSquares(long long n) {

    initializeSeq();

    int fn = seq[n % period];
    int fn1 = seq[(n+1) % period];

    return (fn * fn1) % 10;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << getFibonacciSumSquares(n) << '\n';
}
