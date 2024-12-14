#include <cstdio>
#include <print>
#include <utility>
#include <vector>

static constexpr int X = 101;
static constexpr int Y = 103;

int mod(int a, int b)
{
    int ret = a % b;
    if (ret < 0) {
        ret += b;
    }
    return ret;
}

std::pair<int, int> pos_after_100_moves(int x, int y, int vx, int vy)
{
    x += vx * 100;
    y += vy * 100;

    return std::make_pair(mod(x, X), mod(y, Y));
}

int main()
{
    char line[32] = {0};
    std::vector<std::pair<int, int>> map;

    int x, y, vx, vy;
    while (std::fgets(line, sizeof(line), stdin)) {
        if (std::sscanf(line, "p=%d,%d v=%d,%d", &x, &y, &vx, &vy) == 4) {
            map.push_back(pos_after_100_moves(x, y, vx, vy));
        }
    }

    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (const auto [x, y] : map) {
        if (x < X / 2 && y < Y / 2) {
            q1++;
        }
        else if (x < X / 2 && y > Y / 2) {
            q2++;
        }
        else if (x > X / 2 && y < Y / 2) {
            q3++;
        }
        else if (x > X / 2 && y > Y / 2) {
            q4++;
        }
    }

    std::println("{}", q1 * q2 * q3 * q4);
}
