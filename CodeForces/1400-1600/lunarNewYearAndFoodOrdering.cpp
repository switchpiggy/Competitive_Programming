#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[100007], c[100007];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(ll i = 1; i <= n; ++i) {
        cin >> c[i];
        pq.push({c[i], i});
    }

    for(ll i = 0; i < m; ++i) {
        ll t, d;
        cin >> t >> d;

        if(d <= a[t]) {
            a[t] -= d;
            cout << d * c[t] << '\n';
            continue;
        }

        ll ans = a[t] * c[t];
        d -= a[t];
        a[t] = 0;

        while(!pq.empty() && d) {
            pair<ll, ll> p = pq.top();
            pq.pop();

            ll cur = min(d, a[p.second]);
            d -= cur;
            a[p.second] -= cur;

            ans += cur * p.first;
            if(a[p.second]) {
                pq.push({p.first, p.second});
            }
        }

        if(d) cout << 0 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}