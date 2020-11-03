#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll nb, ns, nc, pb, ps, pc, b, ss, c, r;
string s;

bool check(ll x) {
    ll d = b * x - nb, e = ss * x - ns, f = c * x - nc;
    d = max(0ll, d), e = max(0ll, e), f = max(0ll, f);
    return d * pb + e * ps + f * pc <= r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'B') b++;
        else if(s[i] == 'S') ss++;
        else c++;
    }

    ll l = 0, r = 100000000000000, ans = 0;
    while(l < r) {
        ll m = (l + r)/2;
        if(check(m)) {
            ans = m;
            l = m + 1;
        } else r = m;
    }

    cout << ans << '\n';
    return 0;
}