#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, ans[200007];

struct cmp {
    bool operator() (const pair<ll, ll> &x, const pair<ll, ll> &y) const {
        if(x.second - x.first + 1 == y.second - y.first + 1) return x.first < y.first;
        return x.second - x.first + 1 > y.second - y.first + 1;
    }
};

set<pair<ll, ll>, cmp> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        s.clear();
        s.insert(make_pair(1, n));

        ll cur = 1;
        while(!s.empty()) {
            pair<ll, ll> a = *s.begin();
            s.erase(a);

            ll m = (a.first + a.second)/2;
            ans[m] = cur;

            cur++;
            if(m - 1 >= a.first) s.insert(make_pair(a.first, m - 1));
            if(m + 1 <= a.second) s.insert(make_pair(m + 1, a.second));
        }

        for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}