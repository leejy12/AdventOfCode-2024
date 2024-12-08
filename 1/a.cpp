#include <algorithm>
#include <iostream>
#include <numeric>
#include <print>
#include <ranges>
#include <vector>

int main()
{
    int l, r;
    std::vector<int> left, right;

    while (std::cin >> l >> r) {
        left.push_back(l);
        right.push_back(r);
    }

    std::ranges::sort(left);
    std::ranges::sort(right);

    const auto diffs = std::views::zip_transform([](int x, int y) { return std::abs(x - y); }, left, right);
    const auto answer = std::accumulate(diffs.begin(), diffs.end(), 0);

    std::println("{}", answer);
}
