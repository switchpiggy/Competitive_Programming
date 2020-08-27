#include <bits/stdc++.h>

using namespace std;

int n;

vector<pair<int, int>> adj[1000005];

int dfs(int x, int prev = 0) {

    int res = 0;

    for(auto i : adj[x]) {

        if(prev != i.first) res = max(res, i.second + dfs(i.first, x));

    }

    return res;

}

int main() {

    scanf("%d", &n);

    int a, b, c;

    for(int i = 0; i < n; ++i) {

        scanf("%d %d %d", &a, &b, &c);

        adj[a].push_back(make_pair(b, c));

        adj[b].push_back(make_pair(a, c));

    }
    
    printf("%d\n", dfs(0));

}   