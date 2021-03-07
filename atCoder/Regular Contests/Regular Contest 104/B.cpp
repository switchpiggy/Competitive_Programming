#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, pref[5007][4];
string s;

ll get(ll x, ll y, ll i) {
    return pref[y][i] - (x ? pref[x - 1][i] : 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'A') pref[i][0]++;
        else if(s[i] == 'T') pref[i][1]++;
        else if(s[i] == 'C') pref[i][2]++;
        else pref[i][3]++;
    }

    for(ll i = 1; i < n; ++i) {
        pref[i][0] += pref[i - 1][0];
        pref[i][1] += pref[i - 1][1];
        pref[i][2] += pref[i - 1][2];
        pref[i][3] += pref[i - 1][3];
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            if(get(i, j, 0) == get(i, j, 1) && get(i, j, 3) == get(i, j, 2)) ans++;
        }
    }

    cout << ans << '\n';
}