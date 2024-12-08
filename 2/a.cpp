#include <iostream>
#include <print>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>

bool is_safe(const auto &v)
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

        if (is_safe(v)) {
            cnt++;
        }
    }

    std::println("{}", cnt);
}
