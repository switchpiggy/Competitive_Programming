#include <bits/stdc++.h>

using namespace std;

bool adj[4005][4005];

long long int edges[4005];

int main() {

    long long int n, m;

    scanf("%lld %lld", &n, &m);

    for(long long int i = 0; i < m; ++i) {

        long long int a, b;

        scanf("%lld %lld", &a, &b);

        adj[a][b] = adj[b][a] = 1;

        edges[a]++;

        edges[b]++;

    }

    long long int ans = INT_MAX;

    bool flag = true;

    for(long long int a = 1; a <= n; ++a) {

        for(long long int b = a + 1; b <= n; ++b) {

            if(a != b && adj[a][b] == true)

                for(long long int c = 1; c <= n; ++c) {

                    if(adj[b][c] && adj[c][a] && b != c) {

                        ans = min(ans, edges[a] + edges[b] + edges[c]);

                        flag = false;

                    }

                }

        }

    }

    if(flag) printf("-1");

    else printf("%lld", ans - 6);

}