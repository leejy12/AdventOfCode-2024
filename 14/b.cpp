#include <array>
#include <cstdio>
#include <cstring>
#include <format>
#include <fstream>
#include <print>
#include <vector>

static constexpr int X = 101;
static constexpr int Y = 103;

char map[Y][X] = {0};

int mod(int a, int b)
{
    int ret = a % b;
    if (ret < 0) {
        ret += b;
    }
    return ret;
}

bool has_consecutive_Os(const char str[X])
{
    int count = 0;

    for (int i = 0; i < X; i++) {
        if (str[i] == 'O') {
            count++;
            if (count >= 10) {
                return true;
            }
        }
        else {
            count = 0;
        }
    }

    return false;
}

bool is_tree_possible()
{
    bool result = false;
    for (int y = 0; y < Y; y++) {
        result = result || has_consecutive_Os(map[y]);
        if (result) {
            return true;
        }
    }
    return false;
}

void move_robots(std::vector<std::array<int, 4>>& v)
{
    for (auto& [x, y, vx, vy] : v) {
        x = mod(x + vx, X);
        y = mod(y + vy, Y);
    }
}

void print_robots(const std::vector<std::array<int, 4>>& v, int elapsed)
{
    std::memset(map, '.', sizeof(map));

    for (const auto [x, y, vx, vy] : v) {
        map[y][x] = 'O';
    }

    if (is_tree_possible()) {
        std::ofstream f(std::format("{}.txt", elapsed));
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                std::print(f, "{}", map[i][j]);
            }
            std::println(f);
        }
    }
}

int main()
{
    char line[32] = {0};
    std::vector<std::array<int, 4>> v;
    v.reserve(500);

    int x, y, vx, vy;
    while (std::fgets(line, sizeof(line), stdin)) {
        if (std::sscanf(line, "p=%d,%d v=%d,%d", &x, &y, &vx, &vy) == 4) {
            v.push_back({x, y, vx, vy});
        }
    }

    int elapsed = 0;
    while (elapsed < 10000) {
        print_robots(v, elapsed);
        move_robots(v);
        elapsed++;
    }
}
