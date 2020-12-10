#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

static const int MAXM = 50;

int main()
{
    srand(1);

    int a[4];
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);

    int M = std::max(2, std::min(MAXM, *std::max_element(a, a + 4)));
    std::vector<std::string> g;

    for (int k = 0; k < 4; ++k) {
        int islands = a[(k + 1) % 4] - 1;
        std::string s(M, 'A' + k);
        std::vector<std::pair<int, int>> pos;

        g.push_back(s);
        for (int x = 0; x < (islands + (M - 2)) / (M - 1); ++x) {
            for (int i = 0; i < 3; ++i) g.push_back(s);
            for (int i = (x & 1); i < M - !(x & 1); ++i)
                pos.push_back({(int)g.size() - 2 - ((i ^ x) & 1), i});
        }

        std::random_shuffle(pos.begin(), pos.end());
        for (int i = 0; i < islands; ++i)
            g[pos[i].first][pos[i].second] = 'A' + (k + 1) % 4;
    }

    if (g.size() <= M) {
        printf("%lu %d\n", g.size(), M);
        for (int i = 0; i < g.size(); ++i) puts(g[i].c_str());
    } else {
        printf("%d %lu\n", M, g.size());
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < g.size(); ++j) putchar(g[j][i]);
            putchar('\n');
        }
    }

    return 0;
}