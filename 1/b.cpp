#include <iostream>
#include <map>
#include <print>

int main() {
    int l, r;
    std::map<int, int> left, right;

    while (std::cin >> l >> r) {
        left[l]++;
        right[r]++;
    }

    int score = 0;
    for (const auto [n, cnt] : left) {
        if (right.contains(n)) {
            score += n * left[n] * right[n];
        }
    }

    std::println("{}", score);
}
