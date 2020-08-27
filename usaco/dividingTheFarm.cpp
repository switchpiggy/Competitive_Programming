#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[4007], u, v, res = INT_MAX, color[4007];
vector<ll> adj[4007];
bool visited[4007];

ll getSum(ll x, ll y) {
    bool flag1 = false, flag2 = false;
	//cout << x << endl << y << endl;
	memset(color, 0, sizeof(color));
    ll num1 = 0, num2 = 0;
    stack<ll> s, t;
    s.push(x);
    t.push(y);
    while(!s.empty()) {
        ll to = s.top();
        s.pop();
        if(color[to] != 1) num1 += a[to];
        color[to] = 1;

        for(ll i = 0; i < adj[to].size(); ++i) if(color[adj[to][i]] != 1) {
            if(adj[to][i] == y) {
                if(flag1) {
                    s.push(adj[to][i]);
                } else flag1 = 1;
            } else {
                s.push(adj[to][i]);
            }

        }
    }

    while(!t.empty()) {
        ll to = t.top();
        t.pop();
        if(color[to] == 1) {
        	//cout << "no" << endl;
        	return -1;
        }
        if(color[to] != 2) num2 += a[to];
        color[to] = 2;
        
        for(ll i = 0; i < adj[to].size(); ++i) if(color[adj[to][i]] != 2) {
            if(adj[to][i] == x) {
                if(flag2) {
                    t.push(adj[to][i]);
                } else flag2 = 1;
            } else {
                t.push(adj[to][i]);
            }
        }
    }
    
	//cout << abs(num2 - num1) << endl;
    return abs(num2 - num1);
}

void dfs(ll x) {
    visited[x] = 1;

    for(ll i = 0; i < adj[x].size(); ++i) {
        if(x != adj[x][i]) {
            ll cur = getSum(x, adj[x][i]);
            if(cur != -1) res = min(res, cur); 
            if(!visited[adj[x][i]]) dfs(adj[x][i]);
        }
    }
}

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    printf("%lld\n", res);

    return 0;
}