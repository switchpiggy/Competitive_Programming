#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r, pref[100007][3];
string s;

int main() {
    cin >> s >> n;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'x') pref[i + 1][0]++;
        if(s[i] == 'y') pref[i + 1][1]++;
        if(s[i] == 'z') pref[i + 1][2]++;
    }    

    for(ll i = 1; i <= (ll)s.length(); ++i) {
        pref[i][0] += pref[i - 1][0];
        pref[i][1] += pref[i - 1][1];
        pref[i][2] += pref[i - 1][2];
    }

    for(ll i = 0; i < n; ++i) {
        cin >> l >> r;
        ll x = pref[r][0] - pref[l - 1][0], y = pref[r][1] - pref[l - 1][1], z = pref[r][2] - pref[l - 1][2];

        if((abs(x - y) <= 1 && abs(y - z) <= 1 && abs(x - z) <= 1) || (r - l + 1 <= 2)) {
            cout << "YES\n";
        } else cout << "NO\n";
    }

    return 0;
}