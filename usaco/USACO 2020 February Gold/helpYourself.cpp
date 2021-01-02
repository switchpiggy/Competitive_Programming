#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, pref[200007], p[200007];
vector<pair<ll, ll>> v;

const ll MOD = 1e9 + 7;

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("help");
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
        pref[a]++;
        pref[b]--;
    }

    for(ll i = 1; i <= 2 * n; ++i) pref[i] += pref[i - 1];

    p[0] = 1;
    for(ll i = 1; i <= 2 * n; ++i) p[i] = (p[i - 1] * 2)%MOD;

    ll ans = 0;
    for(ll i = 0; i < n; ++i) ans = (ans + p[n - 1 - pref[v[i].first - 1]])%MOD;
    cout << ans << '\n';
    return 0;
}