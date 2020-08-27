#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200005];

bool visited[200005];

int n, m;

vector<int> res;

map<int, int> deg;

void dfs(int x) {

    res.push_back(x);

    visited[x] = 1;

    for(int i = 0; i < adj[x].size(); ++i) {

        if(!visited[adj[x][i]]) dfs(adj[x][i]);

    }

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i) {

        int a, b;

        scanf("%d %d", &a, &b);

        adj[a].push_back(b);

        adj[b].push_back(a);

        deg[a]++;

        deg[b]++;

    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) {

        if(!visited[i]) {

            res.clear();

            dfs(i);

            bool flag = true;

            for(int i = 0; i < res.size(); ++i) if(deg[res[i]] != 2) flag = false;

            if(flag) ans++;

        }

    }

    printf("%d", ans);

}