#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
map<pair<ll, ll>, ll> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        string s = to_string(i);
        m[{(s[0] - '0'), (s.back() - '0')}]++;
    }

    for(ll i = 1; i <= n; ++i) {
        string s = to_string(i);
        ans += m[{(s.back() - '0'), (s[0] - '0')}];
    }

    cout << ans << '\n';
    return 0;
}