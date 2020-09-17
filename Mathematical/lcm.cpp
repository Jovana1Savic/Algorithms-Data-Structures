#include <iostream>

using namespace std;

int greatestCommonDiv(int a, int b) {
    if (b == 0)
        return a;
    return greatestCommonDiv(b, a % b);
}

long long lcm(int a, int b) {
    if (a < b)
        swap(a, b);
    int gcd = greatestCommonDiv(a, b);
    return 1LL  * a * b / gcd;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
