#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, gcd[200007], v[200007], d[200007], cnt[200007];
vector<ll> adj[200007];
vector<ll> num;

void dfs1(ll x, ll p) {
    for(ll i : adj[x]) {
        if(i == p) continue;
        gcd[i] = __gcd(gcd[x], v[i]);
        d[i] = d[x] + 1;
        dfs1(i, x);
    }

    return;
}

void dfs2(ll x, ll p) {
    for(ll i = 0; i < (ll)num.size(); ++i) {
        if(v[x]%num[i] == 0) {
            cnt[i]++;
            if(cnt[i] >= d[x]) {
                gcd[x] = max(gcd[x], num[i]);
            }
        }
        if(cnt[i] >= d[x]) {
            gcd[x] = max(gcd[x], num[i]);
        }
    }

    for(ll i : adj[x]) {
        if(i == p) continue;
        dfs2(i, x);
    }

    for(ll i = 0; i < (ll)num.size(); ++i) if(v[x]%num[i] == 0) cnt[i]--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> v[i];
    for(ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    gcd[1] = 0;
    dfs1(1, -1);

    for(ll i = 1; i * i <= v[1]; ++i) {
        if(v[1]%i == 0) {
            num.push_back(i);
            if(i != v[1]/i) num.push_back(v[1]/i);
        }
    }

    sort(num.begin(), num.end());
    //gcd[1] = v[1];
    dfs2(1, -1);

    for(ll i = 1; i <= n; ++i) cout << gcd[i] << ' ';
    return 0;
}