#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, pref[2][200007];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll cx = 0, cy = 0;
    cin >> n >> s >> x >> y;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'R') cx++;
        else if(s[i] == 'L') cx--;
        else if(s[i] == 'U') cy++;
        else cy--;
    }

    //cout << cx << ' ' << cy << '\n';
    if(abs(x - cx)%2 == 1 || abs(y - cy)%2 == 1) {
        cout << "-1\n";
        return 0;
    }

    if(x == cx && y == cy) {
        cout << 0 << '\n';
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        if(cx > x && s[i] == 'R') pref[0][i]++;
        if(cx < x && s[i] == 'L') pref[0][i]++;
        if(cy > y && s[i] == 'U') pref[1][i]++;
        if(cy < y && s[i] == 'D') pref[1][i]++;
    }

    for(ll i = 1; i < n; ++i) {
        pref[0][i] += pref[0][i - 1];
        pref[1][i] += pref[1][i - 1];
    }
    ll ans = LONG_LONG_MAX;

    for(ll i = 0; i < n; ++i) {
        ll k = lower_bound(pref[0] + i, pref[0] + n, (i > 0 ? pref[0][i - 1] : 0) + abs(cx - x)/2) - pref[0];
        ll kk = lower_bound(pref[1] + i, pref[1] + n, (i > 0 ? pref[1][i - 1] : 0) + abs(cy - y)/2) - pref[1];
        //cout << kk << ' ' << k << '\n';
        if(k < n && kk < n) ans = min(ans, max(k, kk) - i + 1);
    }

    if(ans == LONG_LONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}