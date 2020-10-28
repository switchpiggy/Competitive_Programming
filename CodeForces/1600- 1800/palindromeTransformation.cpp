#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> s;
    p--;

    if(p >= n/2) {
        reverse(s.begin(), s.end());
        p = n - p - 1;
    }

    ll l = -1, r = -1;
    for(ll i = 0; i < n/2; ++i) {
        if(s[i] != s[n - i - 1]) {
            if(l == -1) l = i;
            r = i;
        }
    }

    if(l == -1 || r == -1) {
        cout << 0 << '\n';
        return 0;
    }

    ll ans = 0;
    if(l <= p && r >= p) {
        ans = min(2 * (p - l) + (r - p), 2 * (r - p) + (p - l));
    } 
    if(l < p && r < p) {
        ans = p - l;
    }
    if(l > p && r > p) {
        ans = r - p;
    }

    for(ll i = 0; i < n/2; ++i) {
        ans += min(abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
    }

    cout << ans << '\n';
    return 0;
}