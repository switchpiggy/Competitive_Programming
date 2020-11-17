#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x[200007], ans[200007];
vector<ll> t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n + m; ++i) cin >> x[i];
    for(ll i = 0; i < n + m; ++i) {
        ll c;
        cin >> c;
        if(c) t.push_back(x[i]);
    }

    for(ll i = 0; i < n + m; ++i) {
        ll l = lower_bound(t.begin(), t.end(), x[i]) - t.begin();
        if(t[l] == x[i]) continue;
        if(l == m) l--;
        if(l > 0) {
            if(abs(t[l - 1] - x[i]) <= abs(t[l] - x[i])) ans[l - 1]++;
            else ans[l]++;
        } else ans[l]++;
    }

    for(ll i = 0; i < m; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}