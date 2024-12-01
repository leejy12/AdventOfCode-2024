#include <iostream>
#include <map>
#include <print>
#include <vector>

int main() {
    int l, r;
    std::vector<int> left;
    std::map<int, int> cnt;

    while (std::cin >> l >> r) {
        left.push_back(l);
        cnt[r]++;
    }

    int score = 0;
    for (const int x : left) {
        if (cnt.contains(x)) {
            score += x * cnt[x];
        }
    }

    std::println("{}", score);
}
