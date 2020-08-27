#include <bits/stdc++.h>

using namespace std;

int n;

bool visited[1005];

int adj[1005];

void dfs(int x) {

    if(visited[x]) {

        cout << x << ' ';

        return;

    } 

    visited[x] = true;

    dfs(adj[x]);
        
    visited[x] = false;


}

int main() {

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {

        int c;

        scanf("%d", &c);

        visited[i] = false;

        adj[i] = c;

    }

    for(int i = 1; i <= n; ++i) {

        dfs(i);

    }



}