#include <iostream>

// Pi(lcm(m,n)) = lcm(Pi(m), Pi(n))
// where Pi(n) is the lenght of period for sequence Fi mod n
//Pi(2) = 3, Pi(5) = 20
//lcm(2, 5) = 10
//therefore Pi(10) = lcm(3,20) = 60

// Sum of n Fibonacci numbers S(n) = F(n+2) - 1
// Threfore S(n) mod 10 = F(n+2) mod 10 - 1


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


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << getFibonacciSum(n);
}
