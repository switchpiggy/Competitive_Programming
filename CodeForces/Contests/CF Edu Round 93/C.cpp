#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, p[100007];
string s;
map<ll, ll> occ;

int main() {
    cin >> t;
    while(t--) {
        occ.clear();
        cin >> n;
        cin >> s;
        ll cnt = 0;
        for(ll i = 0; i <= n; ++i) {
            p[i] = cnt;
            cnt += s[i] - '0';
        }

        ll ans = 0;
        for(ll i = 0; i <= n; ++i) {
            if(occ[p[i] - i]) ans += occ[p[i] - i];
            occ[p[i] - i]++;
        }

        cout << ans << endl;
    }

    return 0;
}