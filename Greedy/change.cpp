#include <iostream>

int get_change(int m) {
    //write your code here
    int ret = 0;
    ret += m / 10;
    m = m % 10;
    ret += m / 5;
    m = m % 5;
    ret += m;
    return ret;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
