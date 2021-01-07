#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//#define benqueue queue
//#define pbenqueue priority_queue
int t, n, m, dp[200007], dist[200007];
vector<int> adj[200007];
queue<int> ben;
bool vis[200007];

void dfs(int x) {
    vis[x] = 1;
    dp[x] = dist[x];
    for(int i : adj[x]) {
        if(!vis[i] && dist[i] > dist[x]) dfs(i);
        
        if(dist[i] > dist[x]) {
            dp[x] = min(dp[x], dp[i]);
        } else dp[x] = min(dp[x], dist[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            dp[i] = 0;
            dist[i] = -1;
            adj[i].clear();
            //adj2[i].clear();
            vis[i] = 0;
        }

        for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        dist[1] = 0;
        ben.push(1);
        while(!ben.empty()) {
            int x = ben.front();
            ben.pop(); 
            //dp[x] = dist[x];

            for(int i : adj[x]) {
                if(dist[i] == -1) {
                    dist[i] = dist[x] + 1;
                    ben.push(i);
                }
            }
        }

        dfs(1);

        for(int i = 1; i <= n; ++i) cout << dp[i] << ' ';
        cout << '\n';
    }

    return 0;
}