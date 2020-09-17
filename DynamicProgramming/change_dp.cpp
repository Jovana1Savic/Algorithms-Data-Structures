#include <iostream>

const int money_max = 1001;
const int num_of_coins = 3;
int money[money_max];
int coins[3] = { 1, 3, 4 };

// coins 1, 3, 4
int get_change(int m) {
    money[0] = 0;

    for (int i = 1; i <= m; i++) {
        int cur_min = m;
        for (int j = 0; j < num_of_coins; j++) {
            if ((i - coins[j] >= 0) && (cur_min > money[i-coins[j]] + 1)) {
                cur_min = money[i - coins[j]] + 1;
            }
        }
        money[i] = cur_min;

    }

    return money[m];
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
