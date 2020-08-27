#include <bits/stdc++.h>

using namespace std;

int maxs = 0;

int far;

int n = 0, m = 0;

vector<int> adj[100005];

void dfs(int cur, int prev, int num) {

    for(int i = 0; i < adj[cur].size(); ++i) {

        if(adj[cur][i] != prev) {

            dfs(adj[cur][i], cur, num + 1);

        }

    }

    if(num > maxs) {

        far = cur;

        maxs = num;

    }

    return;

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i) {

        int a, b;

        scanf("%d %d", &a, &b);

        adj[a].push_back(b);

        adj[b].push_back(a);

    }

    maxs = -1;

    dfs(1, -1, 0);

    dfs(far, -1, 0);

    printf("%d", maxs);

}