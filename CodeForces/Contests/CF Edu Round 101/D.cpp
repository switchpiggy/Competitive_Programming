#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
vector<pair<ll, ll>> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        res.clear();
        if(n <= 8) {
            for(ll i = 2; i < n; ++i) {
                if(i == 2) continue;
                res.push_back({i, i + 1});
            }

            ll k = n;
            while(k > 1) {
                res.push_back({n, 2});
                k = (k + 1)/2;
            }

            cout << (ll)res.size() << '\n';
            for(pair<ll, ll> p : res) cout << p.first << ' ' << p.second << '\n';
            continue;
        }

        for(ll i = 2; i < n; ++i) {
            if(i == 8 || i == 2) continue;
            res.push_back({i, i + 1});
        }

        ll k = n;
        while(k > 1) {
            res.push_back({n, 8});
            k = (k + 7)/8;
        }

        for(ll i = 0; i < 3; ++i) res.push_back({8, 2});

        cout << (ll)res.size() << '\n';
        for(pair<ll, ll> p : res) cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}