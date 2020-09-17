#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, l, r, maxsuf[100007], ans[100007];
vector<pair<pair<ll, ll>, ll>> v;

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b) {
    return a.first.second < b.first.second;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        v.clear();

        for(ll i = 0; i < n; ++i) {
            cin >> l >> r;
            v.push_back(make_pair(make_pair(l, r), i));
        }

        sort(v.begin(), v.end(), cmp);

        ll maxn = INT_MAX;
        for(ll i = n - 1; i >= 0; --i) {
            //maxn = max(maxn, v[i].first);
            maxsuf[i] = maxn;
            maxn = min(maxn, v[i].first.first);
        }
        bool ok = 0;
        for(ll i = 0; i < n - 1; ++i) {
            if(maxsuf[i] > v[i].first.second) {
                for(ll j = 0; j <= i; ++j) ans[v[j].second] = 1;
                for(ll j = i + 1; j < n; ++j) ans[v[j].second] = 2;  

                for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
                cout << '\n';
                ok = 1;

                break;
            } 
        }
        
        if(!ok) cout << "-1\n";
    }

    return 0;
}