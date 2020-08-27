#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, t, a, b;
vector<bool> visited(1005);
vector<ll> color(1005);
bool adj[1005][1005];
vector<pair<ll, ll>> ve(1005);

bool dfs(ll v, ll c) {
	//cout << v << ' ' << c << endl;
    color[v] = c;
    visited[v] = 1;
    for(ll i = 0; i < n; ++i) {
        if(adj[v][i]) {
            if (!visited[i]) {
                bool ret = dfs(i, 1 - c);
                if (!ret) return false;
            } else if(color[v] == color[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%lld", &t);
    for(ll tc = 1; tc <= t; ++tc) {
        scanf("%lld", &n);
        memset(adj, 0, sizeof(adj[0][0]) * 1005 * 1005);
        fill(color.begin(), color.end(), 0);
		fill(visited.begin(), visited.end(), false);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld %lld", &ve[i].first, &ve[i].second);
        }
        
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
            	pair<ll, ll> a,b;
            	if (ve[i].first < ve[j].first) {
            		a = ve[i];
            		b = ve[j];
            	} else {
            		a = ve[j];
            		b = ve[i];
            	}
                if(i != j && (a.second > b.first)) {
                	//cout << ve[i].first << ' ' << ve[i].second << ' ' << ve[j].first << ' ' << ve[j].second << endl;
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
        }
        bool flag = 0;
        for(ll i = 0; i < n; ++i) {
            if(!visited[i]) {
                bool res = dfs(i, 0);
                if(!res) {
                	flag = 1;
                	break;
                }
            }
        }
        printf("Case #%lld: ", tc);
        if(flag) {
            printf("IMPOSSIBLE\n");
        } else {
            for(ll i = 0; i < n; ++i) {
                if(color[i]) printf("J");
                else printf("C");
            }
            printf("\n");
        }
    }
}