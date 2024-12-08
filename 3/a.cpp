#include <cctype>
#include <cstdint>
#include <iostream>
#include <print>
#include <string>

std::int64_t mul(const std::string &s)
{
    int i = 0;
    int status = 0;
    int n1 = 0;
    int n2 = 0;
    std::int64_t ans = 0;

    while (i < s.size()) {
        if (status == 0 && s[i] == 'm') {
            status = 1;
        }
        else if (status == 1 && s[i] == 'u') {
            status = 2;
        }
        else if (status == 2 && s[i] == 'l') {
            status = 3;
        }
        else if (status == 3 && s[i] == '(') {
            status = 4;
        }
        else if (status == 4 && std::isdigit(s[i])) {
            n1 = i;
            status = 5;
        }
        else if (status == 5 && std::isdigit(s[i])) {
            // keep going
        }
        else if (status == 5 && s[i] == ',') {
            status = 6;
        }
        else if (status == 6 && std::isdigit(s[i])) {
            n2 = i;
            status = 7;
        }
        else if (status == 7 && std::isdigit(s[i])) {
            // keep going
        }
        else if (status == 7 && s[i] == ')') {
            ans += std::atoi(&s[n1]) * std::atoi(&s[n2]);
            status = 0;
        }
        else {
            status = 0;
        }
        i++;
    }
    return ans;
}

int main()
{
    std::string s;
    std::int64_t ans = 0;

    while (std::getline(std::cin, s)) {
        ans += mul(s);
    }

    std::println("{}", ans);
}
