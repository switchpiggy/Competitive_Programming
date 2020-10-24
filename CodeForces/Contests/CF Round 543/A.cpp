#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, p[107], s[107], mx[107];
vector<ll> chosen;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i) cin >> p[i];
    for(ll i = 1; i <= n; ++i) {
        cin >> s[i];
        if(mx[s[i]] == 0 || p[mx[s[i]]] < p[i]) mx[s[i]] = i;
    }

    for(ll i = 0; i < k; ++i) {
        ll t;
        cin >> t;
        chosen.push_back(t);
    }

    ll ans = 0;
    for(ll i = 0; i < k; ++i) {
        if(p[chosen[i]] < p[mx[s[chosen[i]]]]) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}