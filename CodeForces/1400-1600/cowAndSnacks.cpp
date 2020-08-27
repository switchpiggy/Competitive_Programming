#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];

bool v[100005];

void dfs(int x) {

    v[x] = 1;

    for(int i = 0; i < adj[x].size(); ++i) if(!v[adj[x][i]]) dfs(adj[x][i]);

    return;

}

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < k; ++i) {

        int a, b;

        scanf("%d %d", &a, &b);

        adj[a].push_back(b);

        adj[b].push_back(a);

    }

    int c = 0;

    for(int i = 1; i <= n; ++i) {

        if(!v[i]) {

            dfs(i);

            c++;

        }

    }

    printf("%d", k - (n - c));

}