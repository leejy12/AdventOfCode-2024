#include <cassert>
#include <cstdlib>
#include <iostream>
#include <print>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

bool is_safe(const auto& v)
{
    int diff = 0;
    for (auto t : v | std::views::adjacent<2>) {
        auto [i, j] = t;
        const int d = i - j;

        if (diff == 0) {
            diff = d;
        }
        else if ((d > 0 && diff < 0) || (d < 0 && diff > 0)) {
            return false;
        }

        const int da = std::abs(d);

        if (da < 1 || da > 3) {
            return false;
        }
    }

    return true;
}

bool is_safe_tolerable_brute_force(const auto& v)
{
    if (is_safe(v)) {
        return true;
    }

    std::vector<int> m;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i != j) {
                m.push_back(v[j]);
            }
        }
        if (is_safe(m)) {
            return true;
        }
        m.clear();
    }

    return false;
}

int main()
{
    std::string s;
    int x = 0;
    int cnt = 0;

    while (std::getline(std::cin, s)) {
        std::stringstream ss(s);
        std::vector<int> v;
        while (ss >> x) {
            v.push_back(x);
        }

        if (is_safe_tolerable_brute_force(v)) {
            cnt++;
        }
    }

    std::println("{}", cnt);
}