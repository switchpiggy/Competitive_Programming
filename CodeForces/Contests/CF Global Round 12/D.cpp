#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007];
multiset<ll> s;

bool check(ll x) {
    s.clear();
    vector<ll> v;
    //ll mins = LONG_LONG_MAX;
    for(ll i = 1; i <= x; ++i) {
        s.insert(a[i]);
    }
    v.push_back(*s.begin());

    for(ll i = x + 1; i <= n; ++i) {
        s.erase(s.find(a[i - x]));
        s.insert(a[i]);
        v.push_back(*s.begin());
    }

    sort(v.begin(), v.end());
    for(ll i = 0; i < (ll)v.size(); ++i) {
        if(v[i] != i + 1) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        ll l = 1, r = n + 1, ans = INT_MAX;

        while(l < r) {
            ll m = (l + r)/2;
            if(check(m)) {
                ans = m;
                r = m;
            } else l = m + 1;
        }

        sort(a + 1, a + n + 1);
        bool ok = 1;
        for(ll i = 1; i < n; ++i) {
            if(a[i] == a[i + 1]) {
                ok = 0;
                break;
            }
        }

        cout << ok;
        for(ll i = 2; i <= n; ++i) if(i >= ans) cout << 1;
        else cout << 0;

        cout << '\n';
    }

    return 0;
}