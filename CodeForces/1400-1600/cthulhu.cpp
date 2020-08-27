#include <bits/stdc++.h>

using namespace std;

int n, m;

bool visited[105];

vector<int> adj[105];

void dfs(int x) {

    visited[x] = true;

    for(int i = 0; i < adj[x].size(); ++i) if(!visited[adj[x][i]]) dfs(adj[x][i]);

}

bool connected() {

    for(int i = 1; i <= n; ++i) if(!visited[i]) return true;

    return false;

}

int main() {

    scanf("%d %d", &n, &m);

    if(n != m) {

        printf("NO");

        return 0;

    }

    for(int i = 0; i < m; ++i) {

        int a, b;

        scanf("%d %d", &a, &b);

        adj[a].push_back(b);

        adj[b].push_back(a);

    }

    dfs(1);

    if(connected()) {

        printf("NO");

    } else printf("FHTAGN!");

}