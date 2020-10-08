#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], occ[11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 1;
    for(ll i = 0; i < n; ++i) {
        occ[a[i]]++;

        vector<ll> v;
        for(ll i = 1; i <= 10; ++i) {
            if(occ[i]) v.push_back(occ[i]);
        }

        sort(v.begin(), v.end());

        //if(v.empty()) continue;
        if((ll)v.size() == 1) {
            ans = max(ans, i + 1);
            continue;
        }

        if(v[0] == 1 && v[1] == v.back()) {
            ans = max(ans, i + 1);
            continue;
        } 

        if(v[0] == v[(ll)v.size() - 2] && v[(ll)v.size() - 1] == v[0] + 1) {
            ans = max(ans, i + 1);
        }
    }
    
    cout << ans << '\n';
    return 0;
}