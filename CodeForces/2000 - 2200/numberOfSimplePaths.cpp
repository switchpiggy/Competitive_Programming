#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, deg[200007], cnt[200007];
vector<ll> adj[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) {
            deg[i] = 0;
            cnt[i] = 1;
            adj[i].clear();
        }
        for(ll i = 1; i <= n; ++i) {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            deg[x]++, deg[y]++;
        }

        benqueue<ll> ben;
        for(ll i = 1; i <= n; ++i) {
            if(deg[i] == 1) ben.push(i);
        }

        while(!ben.empty()) {
            ll f = ben.front();
            ben.pop();
            deg[f] = 0;
            for(ll i : adj[f]) {
                if(!deg[i]) continue;
                deg[i]--;
                if(deg[i] == 1) ben.push(i);
                cnt[i] += cnt[f];
            }
        }

        ll ans = 0;
        for(ll i = 1; i <= n; ++i) {
            if(deg[i] > 1) ans += ((cnt[i] * (cnt[i] - 1))/2) + (cnt[i] * (n - cnt[i]));
        }

        cout << ans << '\n';
    }

    return 0;
}