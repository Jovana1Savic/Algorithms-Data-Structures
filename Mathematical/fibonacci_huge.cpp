#include <iostream>

using namespace std;

const int N_MAX = 10e5 + 1;
int arr[N_MAX * 6 + 10]; // upper bound for pi(m) is 6m

int findPeriod(int* arr, int len) {

    for (int i = 2; i < len - 1; i++) {
        if (arr[i] == arr[0] && arr[i + 1] == arr[1]) {
            return i;
        }
    }

    return -1;
}

int getFibonacciHuge(long long n, int m) {
    if (n <= 1)
        return n;

    arr[0] = 0;
    arr[1] = 1;

    int limit = m * 6 + 10;


    for (int i = 2; i < limit; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % m;
    }
    
    int period = findPeriod(arr, limit);

    return arr[n % period];
    
}

int main() {
    long long n; int m;
    cin >> n >> m;
    cout << getFibonacciHuge(n, m) << '\n';

}
