#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p;
string s;
map<ll, ll> pen;
map<ll, bool> ac;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ll ans = 0, res = 0;
    for(ll i = 0; i < m; ++i) {
        cin >> p >> s;
        if(s == "AC") {
            if(!ac[p]) {
                res += pen[p];
                ac[p] = 1;
                ans++;
            }
        } else {
            pen[p]++;
        }
    }

    cout << ans << ' ' << res << '\n';
    return 0;
}