#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[105];

bool visited[105];

int n, m, q;

bool dfs(int v, int color, int target) {

    visited[v] = 1;

    if(v == target) return true;

    for(int i = 0; i < adj[v].size(); ++i) {

        if(adj[v][i].second == color && !visited[adj[v][i].first]) if(dfs(adj[v][i].first, color, target)) return true;

    }

    return false;

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; ++i) {

        int a, b, color;

        scanf("%d %d %d", &a, &b, &color);

        adj[a].push_back(make_pair(b, color));
        
        adj[b].push_back(make_pair(a, color));
            
    }

    scanf("%d", &q);

    for(int i = 0; i < q; ++i) {

        int res = 0;

        int a, b;

        scanf("%d %d", &a, &b);

        for(int j = 1; j <= 100; ++j) {

            memset((visited), 0, sizeof(visited));

            if(dfs(a, j, b)) res++;

        }

        printf("%d\n", res);

    }



}