#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,k, x, y, c;
bool visited[100005];
vector<ll> edges[100005];
vector<ll> groups[100005];

ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

void dfs(ll level, ll x) {
    if(visited[x]) return;

    visited[x] = 1;
    groups[level].push_back(x);

    for(ll i = 0; i < edges[x].size(); ++i) {
        dfs(level, edges[x][i]);
    }
}

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &x, &y, &c);
        if(c == 0) {
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
    }
    
    ll cur = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dfs(cur, i);
            cur++;
        }
    }

    ll ans = (ll)pow(n, k, 1000000007);

    for(ll i = 0; i < cur; ++i) {
        ans -= (ll)pow(groups[i].size(), k, 1000000007);
        ans += 1000000007;
        ans %= 1000000007;
    }

    printf("%lld", ans);


}